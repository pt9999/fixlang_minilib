#include <stdio.h>
#include <stdlib.h>

#include <uv.h>

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
    CURL *curl;                                 // curl_easy handle
    char error_buf[CURL_ERROR_SIZE];            // a buffer where error messages are written
    BoxedValue boxed_values[MAX_BOXED_VALUES];  // manages many boxed values
} CurlGlue;
*/
// ==================================
// Prototype declarations
// ==================================

/*
int _curl_glue_set_write_callback(CurlGlue* glue);
void _curl_glue_release_boxed_value(CurlGlue* glue, int index);
*/
// ==================================
// Functions
// ==================================

/*
// Initializes a curl_glue structure.
CurlGlue* curl_glue_init() {
    // initializes a curl_easy handle
    CURL* curl = curl_easy_init();
    if (curl == NULL) {
        return NULL;
    }

    // creates a curl_glue structure
    CurlGlue* glue = (CurlGlue*) calloc(1, sizeof(CurlGlue));
    glue->curl = curl;

    // sets the error buffer
    CURLcode res;
    res = curl_easy_setopt(glue->curl, CURLOPT_ERRORBUFFER, glue->error_buf);
    if (res != CURLE_OK) {
        goto error;
    }

    return glue;

error:
    curl_easy_cleanup(glue->curl);
    free(glue);
    return NULL;
}

// Destructs a curl_glue structure.
void curl_glue_cleanup(CurlGlue* glue) {
    if (glue != NULL) {
        if (glue->curl != NULL) {
            curl_easy_cleanup(glue->curl);
            glue->curl = NULL;
        }
        for (int index = 0; index < MAX_BOXED_VALUES; index++) {
            _curl_glue_release_boxed_value(glue, index);
        }
        free(glue);
    }
}

// Sets the target url.
int curl_glue_set_url(CurlGlue* glue, const char* url) {
    CURLcode res = curl_easy_setopt(glue->curl, CURLOPT_URL, url);
    return (int) res;
}

// Sends an HTTP request, and receives an HTTP response.
int curl_glue_perform(CurlGlue* glue) {
    CURLcode res = curl_easy_perform(glue->curl);
    return (int) res;
}

// Retrieves an error message when an error has occured.
const char* curl_glue_get_error_message(CurlGlue* glue) {
    return glue->error_buf;
}

// Sets a boxed value, such as a write callback function.
// the index should be in range: 0 <= index && index < MAX_BOXED_VALUES.
void curl_glue_set_boxed_value(CurlGlue* glue, int index, void* retained_ptr, void (*retain) (void*), void (*release) (void*)) {
    if (index < 0 || MAX_BOXED_VALUES <= index) {
        return;
    }
    BoxedValue boxed = {
        retained_ptr, retain, release
    };
    glue->boxed_values[index] = boxed;
}

void _curl_glue_release_boxed_value(CurlGlue* glue, int index) {
    if (index < 0 || MAX_BOXED_VALUES <= index) {
        return;
    }
    BoxedValue boxed = glue->boxed_values[index];
    if (boxed.retained_ptr == NULL) {
        return;
    }
    if (boxed.release != NULL) {
        //fprintf(stderr, "calling release\n");
        (*boxed.release)(boxed.retained_ptr);
        //fprintf(stderr, "calling release end\n");
    }
    boxed.retained_ptr = NULL;
    boxed.retain = NULL;
    boxed.release = NULL;
    glue->boxed_values[index] = boxed;
}

// Retrieves `retained_ptr` of the specified boxed value.
void* curl_glue_get_boxed_value(CurlGlue* glue, int index) {
    if (index < 0 || MAX_BOXED_VALUES <= index) {
        return NULL;
    }
    BoxedValue boxed = glue->boxed_values[index];
    if (boxed.retained_ptr == NULL) {
        return NULL;
    }
    if (boxed.retain != NULL) {
        //fprintf(stderr, "calling retain\n");
        (*boxed.retain)(boxed.retained_ptr);
        //fprintf(stderr, "calling retain end\n");
    }
    return boxed.retained_ptr;
}

int curl_glue_set_write_callback(CurlGlue* glue) {
    CURLcode res;
    res = curl_easy_setopt(glue->curl, CURLOPT_WRITEDATA, (void*) glue);
    if (res != CURLE_OK) {
        return (int) res;
    }
    extern size_t _callback_write_function(char*, size_t, size_t, void*);
    res = curl_easy_setopt(glue->curl, CURLOPT_WRITEFUNCTION, _callback_write_function);
    return (int) res;
}
*/
