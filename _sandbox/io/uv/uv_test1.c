#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <uv.h>


void fs_open_callback2(uv_fs_t* req) {
    printf("callback2 req=%p data=%p\n", req, req->data);
}

int main() {
    uv_loop_t* loop = uv_default_loop();
    uv_fs_t* req = calloc(sizeof(uv_fs_t), 1);
    const char* path = "tmp.file1.tmp";
    int flags = O_CREAT | O_WRONLY | O_TRUNC;
    int mode = 0666;
    req->data = (void*) 0x123456789abcdef;
    uv_fs_open(loop, req, path, flags, mode, fs_open_callback2);
    uv_run(loop, UV_RUN_DEFAULT);
    uv_fs_req_cleanup(req);
    return 0;
}