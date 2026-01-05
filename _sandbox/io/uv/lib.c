#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <uv.h>

#define LOG_DEBUG(X) printf X
//#define LOG_DEBUG(X)

// ==================================
// Type definitions and constants
// ==================================

#define MAX_BOXED_VALUES 10

typedef struct {
    void* retained_ptr;
    void (*retain) (void*);
    void (*release) (void*);
} BoxedValue;

/*
typedef struct {
    BoxedValue boxed_values[MAX_BOXED_VALUES];  // manages many boxed values
} UvGlue;
*/

// ==================================
// Prototype declarations
// ==================================

void minilib_uv_fs_open_callback(uv_fs_t *req);
//void minilib_uv_fs_write_callback(uv_fs_t *req);

// ==================================
// Functions
// ==================================

// ----------------------------------
// uv_loop_t
// ----------------------------------

uv_loop_t* minilib_uv_loop_init()
{
    uv_loop_t *loop = malloc(sizeof(uv_loop_t));
    if (loop == NULL) return NULL;
    uv_loop_init(loop);
    LOG_DEBUG(("minilib_uv_loop_init loop=%p\n", loop));
    return loop;
}

void minilib_uv_loop_run_default(uv_loop_t* loop)
{
    LOG_DEBUG(("minilib_uv_loop_run_default loop=%p\n", loop));
    uv_run(loop, UV_RUN_DEFAULT);
}

void minilib_uv_loop_close(uv_loop_t* loop)
{
    LOG_DEBUG(("minilib_uv_loop_close loop=%p\n", loop));
    uv_loop_close(loop);
    free(loop);
}

// ----------------------------------
// uv_req_t
// ----------------------------------

typedef void (*minilib_uv_req_cleanup_func)(uv_req_t*);

struct minilib_uv_reqdata_s {
    uv_req_t* req;
    minilib_uv_req_cleanup_func cleanup;
    int refcount;
    void* fix_cb;
    void* client_data;
};
typedef struct minilib_uv_reqdata_s minilib_uv_reqdata_t;

uv_req_t* minilib_uv_req_init(size_t size, void* cleanup_func)
{
    uv_req_t* req = calloc(size, 1);
    if (req == NULL) return NULL;

    minilib_uv_reqdata_t* data = calloc(sizeof(minilib_uv_reqdata_t), 1);
    if (data == NULL) return NULL;
    req->data = data;

    data->req = req;
    data->cleanup = cleanup_func;
    data->refcount = 0;
    data->fix_cb = NULL;
    data->client_data = NULL;

    return req;
}

void minilib_uv_req_retain(uv_req_t* req)
{
    LOG_DEBUG(("minilib_uv_req_retain req=%p\n", req));
    if (req != NULL && req->data != NULL) {
        minilib_uv_reqdata_t* data = req->data;
        data->refcount++;
    }
}

void minilib_uv_req_release(uv_req_t* req)
{
    LOG_DEBUG(("minilib_uv_req_release req=%p\n", req));
    if (req != NULL && req->data != NULL) {
        minilib_uv_reqdata_t* data = req->data;
        data->refcount--;
        if (data->refcount <= 0) {
            minilib_uv_req_cleanup_func cleanup = data->cleanup;
            (*cleanup)(data->req);
            free(req);
            free(data);
        }
    }
}

void minilib_uv_req_set_fix_cb(uv_req_t* req, void* fix_cb)
{
    minilib_uv_reqdata_t* data = req->data;
    data->fix_cb = fix_cb;
    LOG_DEBUG(("minilib_uv_req_set_fix_cb req=%p fix_cb=%p\n", req, fix_cb));
}

void* minilib_uv_req_get_fix_cb(uv_req_t* req)
{
    minilib_uv_reqdata_t* data = req->data;
    return data->fix_cb;
}

void minilib_uv_req_set_client_data(uv_req_t* req, void* client_data)
{
    minilib_uv_reqdata_t* data = req->data;
    data->client_data = client_data;
    LOG_DEBUG(("minilib_uv_req_set_data req=%p client_data=%p\n", req, client_data));
}

void* minilib_uv_req_get_client_data(uv_req_t* req)
{
    minilib_uv_reqdata_t* data = req->data;
    return data->client_data;
}

// ----------------------------------
// uv_fs_t
// ----------------------------------

uv_fs_t* minilib_uv_fs_init()
{
    uv_fs_t *req = (uv_fs_t*) minilib_uv_req_init(sizeof(uv_fs_t), uv_fs_req_cleanup);
    LOG_DEBUG(("minilib_uv_fs_init req=%p\n", req));
    return req;
}


int64_t minilib_uv_fs_get_result(uv_fs_t* req)
{
    ssize_t result = req->result;
    return (int64_t) result;
}

/*
uv_loop_t* minilib_uv_fs_get_loop(uv_fs_t* req)
{
    return req->loop;
}
*/

struct flagnames {
    const char* name;
    int flag;
} flagnames[] = {
    { "O_RDONLY", O_RDONLY },
    { "O_WRONLY", O_WRONLY },
    { "O_RDWR", O_RDWR },
    { "O_CREAT", O_CREAT },
    { "O_EXCL", O_EXCL },
    { "O_TRUNC", O_TRUNC },
    { "O_APPEND", O_APPEND },
};

int minilib_uv_fs_find_flag(const char* flagname)
{
    for (int i = 0; i < sizeof(flagnames) / sizeof(flagnames[0]); i++) {
        if (0 == strcmp(flagname, flagnames[i].name))
            return flagnames[i].flag;
    }
    return 0;
}

int minilib_uv_fs_open(uv_loop_t *loop, uv_fs_t *req, const char *path, int flags, int mode)
{
    LOG_DEBUG(("minilib_uv_fs_open loop=%p req=%p data=%p\n", loop, req, req->data));
    return uv_fs_open(loop, req, path, flags, mode, minilib_uv_fs_open_callback);
}

/*
// たぶん uv_fs_write ではなく uv_write を使うほうが良い

int minilib_uv_fs_write(uv_loop_t *loop, uv_fs_t *req, uv_file file, const uint8_t* buf, size_t buflen)
{
    LOG_DEBUG(("minilib_uv_fs_write loop=%p req=%p\n", loop, req));
    uv_buf_t bufs[1] = {0};
    bufs[0].base = (char*) buf;
    bufs[0].len = buflen;
    unsigned int nbufs = 1;
    int64_t offset = -1;
    return uv_fs_write(loop, req, file, bufs, nbufs, offset, minilib_uv_fs_write_callback);
}
*/
