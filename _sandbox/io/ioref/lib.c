#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct {
    void* retained_ptr;
    void (*retain) (void*);
    void (*release) (void*);
} ioref_t;

ioref_t* minilib_ioref_init(void* retained_ptr, void (*retain) (void*), void (*release) (void*))
{
    ioref_t* ior = calloc(sizeof(ioref_t), 1);
    ior->retained_ptr = retained_ptr;
    ior->retain = retain;
    ior->release = release;
    return ior;
}

void minilib_ioref_cleanup(ioref_t* ior)
{
    if (ior != NULL) {
        if (ior->retained_ptr != NULL && ior->release != NULL)
        {
            (*ior->release)(ior->retained_ptr);
        }
        ior->retained_ptr = NULL;
        ior->retain = NULL;
        ior->release = NULL;
        free(ior);
    }
}

void* minilib_ioref_get_retained_ptr(ioref_t* ior)
{
    if (ior != NULL) {
        return ior->retained_ptr;
    }
    return NULL;
}

void minilib_ioref_set_retained_ptr(ioref_t* ior, void* retained_ptr)
{
    if (ior != NULL) {
        ior->retained_ptr = retained_ptr;
    }
}

void minilib_ioref_retain(ioref_t* ior)
{
    if (ior != NULL) {
        if (ior->retained_ptr != NULL && ior->retain != NULL)
        {
            (*ior->retain)(ior->retained_ptr);
        }
    }
}

void minilib_ioref_release(ioref_t* ior)
{
    if (ior != NULL) {
        if (ior->retained_ptr != NULL && ior->retain != NULL)
        {
            (*ior->release)(ior->retained_ptr);
        }
    }
}

