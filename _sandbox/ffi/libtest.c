#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void *fixruntime_run_function(void *function);

typedef void (*RetainFunc)(void*);
typedef void (*ReleaseFunc)(void*);

typedef struct BoxedValue {
    void* value;
    RetainFunc retain;
    ReleaseFunc release;
} BoxedValue;


BoxedValue* boxedvalue_register (void* p_value, void* p_retain, void* p_release)
{
    BoxedValue* b = (BoxedValue*) calloc(1, sizeof(BoxedValue));
    b->value = p_value;
    b->retain = p_retain;
    b->release = p_release;
    return b;
}

void boxedvalue_retain (BoxedValue* b)
{
    if (b == NULL) return;
    (*b->retain)(b->value);
}

void boxedvalue_release (BoxedValue* b)
{
    if (b == NULL) return;
    (*b->release)(b->value);
}

void boxedvalue_unregister (BoxedValue* b)
{
    if (b == NULL) return;
    (*b->release)(b->value);
    memset(b, 0, sizeof(BoxedValue));
    free(b);
}

void boxedvalue_call(BoxedValue* b)
{
    if (b == NULL) return;

    boxedvalue_retain(b);
    void* ret = fixruntime_run_function(b->value);
    // TODO: release ret
}

//----------------------------

BoxedValue* g_callback = NULL;

void set_callback(BoxedValue* b)
{
    g_callback = b;
}

int test1(int a)
{
    printf("hello world %d\n", a);
    boxedvalue_call(g_callback);
    printf("hoge hoge hoge\n");
    return a + 34;
}
