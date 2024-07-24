#ifndef _FUNC_H_
#define _FUNC_H_
#include "func1.h"

#define DEBUG
#ifdef DEBUG
    #define D if(1)
#else
    #define D if(0)
#endif


typedef int datatype;

typedef struct list
{
    datatype value;
    struct list *next;
} stack;

typedef struct listq
{
    datatype value;
    struct listq *next;
} queue;

typedef struct
{
    datatype *item;
    int size;
    int sp;
} stack_arr;

// Функция доступна только из func.c   
static int max(int, int);
// Функция доступна везде   
int max_3(int, int, int);
extern int m;
#endif