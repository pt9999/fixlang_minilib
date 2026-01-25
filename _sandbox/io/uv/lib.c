#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <uv.h>
#include <dmalloc.h>

//#define LOG_DEBUG(X) printf("\x1b[033m[lib.c]\x1b[m "); printf X
#define LOG_DEBUG(X)

// ==================================
// Type definitions and constants
// ==================================

// ==================================
// Prototype declarations
// ==================================

// in lib.c
void minilib_uv_handle_close_callback(uv_handle_t* handle);
void minilib_uv_handle_dealloc(uv_handle_t* handle);

// in uv.fix
void minilib_uv_timer_callback(uv_timer_t *timer);
void minilib_uv_idle_callback(uv_idle_t *timer);
void minilib_uv_fs_open_callback(uv_fs_t *req);
void minilib_uv_fs_close_callback(uv_fs_t *req);
void minilib_uv_fs_read_callback(uv_fs_t *req);
void minilib_uv_fs_write_callback(uv_fs_t *req);
void minilib_uv_write_callback(uv_write_t *req, int status);
void minilib_uv_read_callback(uv_stream_t *stream, int64_t nread, const char* buf);


// ==================================
// Functions
// ==================================

// ----------------------------------
// Error handling
// ----------------------------------

int minilib_uv_get_uv_eof()
{
    return UV_EOF;
}

// ----------------------------------
// Memory Management
// ----------------------------------

void* minilib_uv_malloc(size_t size)
{
    return malloc(size);
}

void minilib_uv_free(void* ptr)
{
    free(ptr);
}

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

/*
int minilib_atexit_cb_registered = 0;
void minilib_atexit_cb()
{
    uv_loop_t* loop = uv_default_loop();
    if (loop != NULL) {
        uv_loop_close(loop);
    }
}
*/

uv_loop_t* minilib_uv_get_default_loop()
{
    /*
    // TODO: thread safety
    if (!minilib_atexit_cb_registered) {
        atexit(&minilib_atexit_cb);
        minilib_atexit_cb_registered = 1;
    }
    */
    return uv_default_loop();
}

// ----------------------------------
// uv_handle_t
// ----------------------------------
struct minilib_uv_handledata_s {
    void* fix_cb;
    int started;
    void* extra_data;
};
typedef struct minilib_uv_handledata_s minilib_uv_handledata_t;

uv_handle_t* minilib_uv_handle_init(uv_handle_t* handle)
{
    if (handle == NULL) return NULL;
    minilib_uv_handledata_t* data = malloc(sizeof(minilib_uv_handledata_t));
    if (data == NULL) return NULL;
    handle->data = data;

    data->fix_cb = NULL;
    data->started = 0;
    data->extra_data = NULL;
    return handle;
}

// ユーザから呼び出される
void minilib_uv_handle_close(uv_handle_t* handle)
{
    LOG_DEBUG(("minilib_uv_handle_close handle=%p\n", handle));
    if (!uv_is_closing(handle)) {
        // まだクローズされていなければ、クローズ後に解放する
        uv_close(handle, minilib_uv_handle_close_callback);
    } else {
        // 既にクローズされている場合は何もしない
        return;
    }
}


void minilib_uv_handle_close_callback(uv_handle_t* handle)
{
    LOG_DEBUG(("minilib_uv_handle_close_callback handle=%p\n", handle));
    minilib_uv_handle_dealloc(handle);
}

void minilib_uv_handle_dealloc(uv_handle_t* handle)
{
    LOG_DEBUG(("minilib_uv_handle_dealloc handle=%p\n", handle));
    if (handle != NULL) {
        assert(uv_is_closing(handle));
        assert(!uv_is_active(handle));
        //assert(!uv_has_ref(handle));
        minilib_uv_handledata_t* data = handle->data;
        handle->data = NULL;
        LOG_DEBUG(("freeing handle=%p\n", handle));
        free(handle);
        if (data != NULL) {
            free(data);
        }
    }
}

void minilib_uv_handle_set_fix_cb(uv_handle_t* handle, void* fix_cb)
{
    minilib_uv_handledata_t* data = handle->data;
    assert (data->fix_cb == NULL);
    data->fix_cb = fix_cb;
    LOG_DEBUG(("minilib_uv_handle_set_fix_cb handle=%p fix_cb=%p\n", handle, fix_cb));
}

// can be get only once
void* minilib_uv_handle_get_fix_cb(uv_handle_t* handle)
{
    minilib_uv_handledata_t* data = handle->data;
    void* fix_cb = data->fix_cb;
    data->fix_cb = NULL;
    return fix_cb;
}

int minilib_uv_is_started(uv_handle_t *handle)
{
    minilib_uv_handledata_t* data = handle->data;
    return data->started;
}

void minilib_uv_handle_set_extra_data(uv_handle_t* handle, void* extra_data)
{
    minilib_uv_handledata_t* data = handle->data;
    data->extra_data = extra_data;
    LOG_DEBUG(("minilib_uv_handle_set_data handle=%p extra_data=%p\n", handle, extra_data));
}

void* minilib_uv_handle_get_extra_data(uv_handle_t* handle)
{
    minilib_uv_handledata_t* data = handle->data;
    return data->extra_data;
}

// ----------------------------------
// uv_req_t
// ----------------------------------

typedef void (*minilib_uv_req_cleanup_func)(uv_req_t*);

struct minilib_uv_reqdata_s {
    minilib_uv_req_cleanup_func cleanup;
    int refcount;
    void* fix_cb;
    void* extra_data;
};
typedef struct minilib_uv_reqdata_s minilib_uv_reqdata_t;

uv_req_t* minilib_uv_req_init(size_t size, void* cleanup_func)
{
    uv_req_t* req = malloc(size);
    if (req == NULL) return NULL;

    minilib_uv_reqdata_t* data = malloc(sizeof(minilib_uv_reqdata_t));
    if (data == NULL) return NULL;
    req->data = data;

    data->cleanup = cleanup_func;
    data->refcount = 0;
    data->fix_cb = NULL;
    data->extra_data = NULL;

    return req;
}

void minilib_uv_req_retain(uv_req_t* req)
{
    if (req != NULL && req->data != NULL) {
        minilib_uv_reqdata_t* data = req->data;
        LOG_DEBUG(("minilib_uv_req_retain req=%p type=%d refcount: %d -> %d\n", req, type, data->refcount, data->refcount+1));
        data->refcount++;
    }
}

void minilib_uv_req_release(uv_req_t* req)
{
    if (req != NULL && req->data != NULL) {
        minilib_uv_reqdata_t* data = req->data;
        LOG_DEBUG(("minilib_uv_req_release req=%p type=%d refcount: %d -> %d\n", req, type, data->refcount, data->refcount-1));
        data->refcount--;
        if (data->refcount <= 0) {
            minilib_uv_req_cleanup_func cleanup = data->cleanup;
            if (cleanup != NULL) {
                (*cleanup)(req);
            }
            LOG_DEBUG(("freeing req=%p\n", req));
            free(req);
            free(data);
        }
    }
}

void minilib_uv_req_set_fix_cb(uv_req_t* req, void* fix_cb)
{
    minilib_uv_reqdata_t* data = req->data;
    assert (data->fix_cb == NULL);
    data->fix_cb = fix_cb;
    LOG_DEBUG(("minilib_uv_req_set_fix_cb req=%p fix_cb=%p\n", req, fix_cb));
}

// can be get only once
void* minilib_uv_req_get_fix_cb(uv_req_t* req)
{
    minilib_uv_reqdata_t* data = req->data;
    void* fix_cb = data->fix_cb;
    data->fix_cb = NULL;
    return fix_cb;
}

void minilib_uv_req_set_extra_data(uv_req_t* req, void* extra_data)
{
    minilib_uv_reqdata_t* data = req->data;
    data->extra_data = extra_data;
    LOG_DEBUG(("minilib_uv_req_set_extra_data req=%p extra_data=%p\n", req, extra_data));
}

void* minilib_uv_req_get_extra_data(uv_req_t* req)
{
    minilib_uv_reqdata_t* data = req->data;
    return data->extra_data;
}

// ----------------------------------
// uv_timer_t
// ----------------------------------

uv_timer_t* minilib_uv_timer_init(uv_loop_t* loop)
{
    uv_timer_t *timer = (uv_timer_t*) minilib_uv_handle_init(malloc(sizeof(uv_timer_t)));
    if (timer == NULL) return NULL;
    LOG_DEBUG(("minilib_uv_timer_init timer=%p\n", timer));
    int err = uv_timer_init(loop, timer);
    if (err < 0) {
        minilib_uv_handle_dealloc((uv_handle_t*) timer);
        return NULL;
    }
    return timer;
}

void minilib_uv_timer_cb(uv_timer_t *timer)
{
    LOG_DEBUG(("minilib_uv_timer_cb timer=%p\n", timer));
    minilib_uv_timer_callback(timer);
}

int minilib_uv_timer_start(uv_timer_t *timer, uint64_t timeout, uint64_t repeat)
{
    LOG_DEBUG(("minilib_uv_timer_start timer=%p\n", timer));
    minilib_uv_handledata_t* data = ((uv_handle_t*)timer)->data;
    if (data->started) return UV_EALREADY;
    int err = uv_timer_start(timer, minilib_uv_timer_cb, timeout, repeat);
    LOG_DEBUG(("minilib_uv_timer_start err=%d\n", err));
    if (err < 0) return err;
    data->started = 1;
    return err;
}

int minilib_uv_timer_stop(uv_timer_t *timer)
{
    LOG_DEBUG(("minilib_uv_timer_stop timer=%p\n", timer));
    minilib_uv_handledata_t* data = ((uv_handle_t*)timer)->data;
    if (!data->started) return 0;
    int err = uv_timer_stop(timer);
    LOG_DEBUG(("minilib_uv_timer_stop err=%d\n", err));
    if (err < 0) return err;
    data->started = 0;
    return err;
}


// ----------------------------------
// uv_idle_t
// ----------------------------------

uv_idle_t* minilib_uv_idle_init(uv_loop_t* loop)
{
    uv_idle_t *idle = (uv_idle_t*) minilib_uv_handle_init(malloc(sizeof(uv_idle_t)));
    if (idle == NULL) return NULL;
    LOG_DEBUG(("minilib_uv_idle_init idle=%p\n", idle));
    int err = uv_idle_init(loop, idle);
    if (err < 0) {
        minilib_uv_handle_dealloc((uv_handle_t*) idle);
        return NULL;
    }
    return idle;
}

void minilib_uv_idle_cb(uv_idle_t *idle)
{
    LOG_DEBUG(("minilib_uv_idle_cb idle=%p\n", idle));
    minilib_uv_idle_callback(idle);
}

int minilib_uv_idle_start(uv_idle_t *idle)
{
    LOG_DEBUG(("minilib_uv_idle_start idle=%p\n", idle));
    minilib_uv_handledata_t* data = ((uv_handle_t*)idle)->data;
    if (data->started) return UV_EALREADY;
    int err = uv_idle_start(idle, minilib_uv_idle_cb);
    LOG_DEBUG(("minilib_uv_idle_start err=%d\n", err));
    if (err < 0) return err;
    data->started = 1;
    return err;
}

int minilib_uv_idle_stop(uv_idle_t *idle)
{
    LOG_DEBUG(("minilib_uv_idle_stop idle=%p\n", idle));
    minilib_uv_handledata_t* data = ((uv_handle_t*)idle)->data;
    if (!data->started) return 0;
    int err = uv_idle_stop(idle);
    LOG_DEBUG(("minilib_uv_idle_stop err=%d\n", err));
    if (err < 0) return err;
    data->started = 0;
    return err;
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

int minilib_uv_fs_close(uv_loop_t *loop, uv_fs_t *req, uv_file file)
{
    LOG_DEBUG(("minilib_uv_fs_close loop=%p req=%p\n", loop, req));
    return uv_fs_close(loop, req, file, minilib_uv_fs_close_callback);
}

int minilib_uv_fs_read(uv_loop_t *loop, uv_fs_t *req, uv_file file, const uint8_t* buf, size_t buflen)
{
    LOG_DEBUG(("minilib_uv_fs_read loop=%p req=%p\n", loop, req));
    uv_buf_t bufs[1] = {0};
    bufs[0].base = (char*) buf;
    bufs[0].len = buflen;
    unsigned int nbufs = 1;
    int64_t offset = -1;
    return uv_fs_read(loop, req, file, bufs, nbufs, offset, minilib_uv_fs_read_callback);
}

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

// ----------------------------------
// uv_stream_t
// ----------------------------------

void minilib_uv_read_alloc_cb(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf)
{
    LOG_DEBUG(("minilib_uv_read_alloc_cb suggested_size=%lu\n", (uint64_t) suggested_size));
    buf->base = malloc(suggested_size);
    buf->len = suggested_size;
}

void minilib_uv_read_cb(uv_stream_t *stream, ssize_t nread, const uv_buf_t *buf)
{
    LOG_DEBUG(("minilib_uv_read_cb nread=%ld\n", (int64_t) nread));
    minilib_uv_read_callback(stream, (int64_t) nread, buf->base);
    free(buf->base);
}

int minilib_uv_read_start(uv_stream_t *stream)
{
    LOG_DEBUG(("minilib_uv_read_start stream=%p\n", stream));
    minilib_uv_handledata_t* data = ((uv_handle_t*)stream)->data;
    if (data->started) return UV_EALREADY;
    int err = uv_read_start(stream, minilib_uv_read_alloc_cb, minilib_uv_read_cb);
    LOG_DEBUG(("minilib_uv_read_start err=%d\n", err));
    if (err < 0) return err;
    data->started = 1;
    return err;
}

int minilib_uv_read_stop(uv_stream_t *stream)
{
    LOG_DEBUG(("minilib_uv_read_stop stream=%p\n", stream));
    minilib_uv_handledata_t* data = ((uv_handle_t*)stream)->data;
    if (!data->started) return 0;
    int err = uv_read_stop(stream);
    if (err < 0) return err;
    data->started = 0;
    return err;
}


// ----------------------------------
// uv_write_t
// ----------------------------------

uv_write_t* minilib_uv_write_init()
{
    return (uv_write_t*) minilib_uv_req_init(sizeof(uv_write_t), NULL);
}

int minilib_uv_write(uv_write_t *write_req, uv_stream_t *handle, const char* buf, size_t bufsize)
{
    uv_buf_t bufs[1] = {0};
    bufs[0].base = (char*) buf;
    bufs[0].len = bufsize;
    unsigned int nbufs = 1;
    return uv_write(write_req, handle, bufs, nbufs, minilib_uv_write_callback);
}
 
uv_stream_t* minilib_uv_write_get_stream(uv_write_t* write_req)
{
    return write_req->handle;
}

// ----------------------------------
// uv_pipe_t
// ----------------------------------

uv_pipe_t* minilib_uv_pipe_init(uv_loop_t* loop)
{
    uv_pipe_t *pipe = (uv_pipe_t*) minilib_uv_handle_init(malloc(sizeof(uv_pipe_t)));
    if (pipe == NULL) return NULL;
    LOG_DEBUG(("minilib_uv_pipe_init pipe=%p\n", pipe));
    int ipc = 0;
    int err = uv_pipe_init(loop, pipe, ipc);
    if (err < 0) {
        minilib_uv_handle_dealloc((uv_handle_t*) pipe);
        return NULL;
    }
    return pipe;
}

int minilib_uv_pipe_open(uv_pipe_t* pipe, uv_file file)
{
    return uv_pipe_open(pipe, file);
}

int minilib_uv_make_pipe_pair(uv_file fds[2])
{
    return uv_pipe(fds, UV_NONBLOCK_PIPE, UV_NONBLOCK_PIPE);
}
