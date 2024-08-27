#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// type definitions
#define MAX_BOXED_VALUES 10

typedef struct {
    CURL *curl;
    char error_buf[CURL_ERROR_SIZE];
    void* boxed_values[MAX_BOXED_VALUES];
} CurlGlue;

// prototype declarations
int _curl_glue_set_write_callback(CurlGlue* glue);


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

    res = (CURLcode) _curl_glue_set_write_callback(glue);
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

void curl_glue_set_boxed_value(CurlGlue* glue, int index, void* ptr) {
    if (0 <= index && index < MAX_BOXED_VALUES) {
        glue->boxed_values[index] = ptr;
    }
}

void* curl_glue_get_boxed_value(CurlGlue* glue, int index) {
    if (0 <= index && index < MAX_BOXED_VALUES) {
        return glue->boxed_values[index];
    }
    return NULL;
}

int _curl_glue_set_write_callback(CurlGlue* glue) {
    CURLcode res;
    res = curl_easy_setopt(glue->curl, CURLOPT_WRITEDATA, (void*) glue);
    if (res != CURLE_OK) {
        return (int) res;
    }
    extern size_t _callback_write_function(char*, size_t, size_t, void*);
    res = curl_easy_setopt(glue->curl, CURLOPT_WRITEFUNCTION, _callback_write_function);
    return (int) res;
}

