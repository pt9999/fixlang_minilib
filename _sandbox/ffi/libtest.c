#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void *fixruntime_run_function(void *function);

//-------------------------------------------------------------
//  FixのBoxedオブジェクトをC側に渡す仕組み

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

//-------------------------------------------------------------
// Fixの関数をCから呼ぶ仕組み

/*
typedef struct CallbackFunc {
    BoxedValue* func;
    void* args;
    void* result;
} CallbackFunc;

CallbackFunc* cb_create()
{

}
*/

typedef struct Vec {
    int x;
    int y;
    int z;
} Vec;

Vec* g_vec = NULL;

void access_vec(Vec* p)
{
    g_vec = p;
}

void boxedvalue_call(BoxedValue* b)
{
    fprintf(stderr, "boxedvalue_call start: b=%p\n", b);
    if (b == NULL) return;

    boxedvalue_retain(b);
    void* returned_value = fixruntime_run_function(b->value);
    // NOTE: `returned_value` is a retained pointer.
    //       It is released by Fix runtime. ?
    fprintf(stderr, "returned_value=%p\n", returned_value);
    fprintf(stderr, "0[(int*)returned_value]=%d\n", 0[(int*)returned_value]);
    fprintf(stderr, "1[(int*)returned_value]=%d\n", 1[(int*)returned_value]);
    fprintf(stderr, "2[(int*)returned_value]=%d\n", 2[(int*)returned_value]);
    fprintf(stderr, "3[(int*)returned_value]=%d\n", 3[(int*)returned_value]);
    g_vec->z = 3001;
    fprintf(stderr, "boxedvalue_call end\n");
}

//----------------------------
// use case
//----------------------------

BoxedValue* g_callback = NULL;

void set_callback(BoxedValue* b)
{
    g_callback = b;
}

int c_function_1(int arg)
{
    fprintf(stderr, "c_function_1 start: arg=%d\n", arg);
    boxedvalue_call(g_callback);
    fprintf(stderr, "c_function_1 end\n");
    return arg + 23;
}
