#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// type definitions
typedef void CurlGlueWriteFunc(char *ptr, size_t size, size_t nmemb, int* result);

typedef struct {
    CURL *curl;
    char error_buf[CURL_ERROR_SIZE];
    CurlGlueWriteFunc* write_func;
    void* fix_value1;
} CurlGlue;

// prototype declarations
int curl_glue_set_write_func(CurlGlue* glue, CurlGlueWriteFunc* write_func);


CurlGlue* curl_glue_init() {
    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        return NULL;
    }

    CurlGlue* glue = (CurlGlue*) calloc(1, sizeof(CurlGlue));
    glue->curl = curl;

    CURLcode res;
    res = curl_easy_setopt(glue->curl, CURLOPT_ERRORBUFFER, glue->error_buf);
    if (res != CURLE_OK) {
        goto error;
    }

    res = (CURLcode) curl_glue_set_write_func(glue, NULL);
    if (res != CURLE_OK) {
        goto error;
    }

    return glue;

error:
    curl_easy_cleanup(glue->curl);
    free(glue);
    return NULL;
}

void curl_glue_cleanup(CurlGlue* glue) {
    if (glue != NULL) {
        if (glue->curl != NULL) {
            curl_easy_cleanup(glue->curl);
            glue->curl = NULL;
        }
        free(glue);
    }
}

int curl_glue_set_url(CurlGlue* glue, const char* url) {
    CURLcode res = curl_easy_setopt(glue->curl, CURLOPT_URL, url);
    return (int) res;
}

int curl_glue_perform(CurlGlue* glue) {
    CURLcode res = curl_easy_perform(glue->curl);
    return (int) res;
}

const char* curl_glue_get_error_message(CurlGlue* glue) {
    return glue->error_buf;
}

void curl_glue_set_fix_value1(CurlGlue* glue, void* ptr) {
    glue->fix_value1 = ptr;
}

void* curl_glue_get_fix_value1(CurlGlue* glue) {
    return glue->fix_value1;
}

size_t _curl_glue_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    CurlGlue* glue = (CurlGlue*) userdata;
    //CurlGlueWriteFunc* write_func = glue->write_func;
    // typedef void CurlGlueWriteFunc(char *ptr, size_t size, size_t nmemb, int* result);
    // TODO: call FFI_EXPORTED function
    extern size_t _callback_write_function(char*, size_t, size_t, void*);
    return _callback_write_function(ptr, size, nmemb, userdata);
}

int curl_glue_set_write_func(CurlGlue* glue, CurlGlueWriteFunc* write_func) {
    glue->write_func = write_func;
    CURLcode res;
    res = curl_easy_setopt(glue->curl, CURLOPT_WRITEDATA, (void*) glue);
    if (res != CURLE_OK) {
        return (int) res;
    }
    res = curl_easy_setopt(glue->curl, CURLOPT_WRITEFUNCTION, _curl_glue_write_callback);
    return (int) res;
}

