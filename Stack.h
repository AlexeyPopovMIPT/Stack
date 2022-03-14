#ifndef _INC_STDIO
#include <stdio.h>
#endif
#ifndef _INC_STDLIB
#include <stdlib.h>
#endif
#ifndef _INC_MATH
#include <math.h>
#endif
#include <assert.h>

#define NewStack(stk, type) MakeStack(&stk, sizeof(type))

struct Stack;

const int DEFAULT_CAPACITY = 32;
const int MIN_REALLOC_DOWN_CAPACITY = 64;

enum errcodes {
	ERR_STACK_EMPTY = -50,
	ERR_WHILE_REALLOCATE_UP,   //нет памяти, чтобы вместить стек на столько элементов, сколько вам нужно.
	                           //возможно, сегментация памяти
	ERR_NO_MEMORY_FOR_STACK, 
	ERR_NO_MEMORY_FOR_BUFFER,
	ERR_SKY_FELL_TO_THE_GROUND
};
enum stk_damaged_errcodes {
	OK = 0,
	ERR_STK_NULL_PTR = -100,
	ERR_BUFFER_NULL_PTR,
	ERR_NEGATIVE_CAPACITY,
	ERR_NEGATIVE_COUNT,
	ERR_COUNT_BIGGER_THAN_CAPACITY,
	ERR_STK_DAMAGED_LEFT,
	ERR_STK_DAMAGED_RIGHT,
	ERR_BUFFER_DAMAGED_LEFT,
	ERR_BUFFER_DAMAGED_RIGHT,
	ERR_BUF_HASH_DIDNT_MATCH,
	ERR_STK_HASH_DIDNT_MATCH
};


extern int    StackPush(Stack* stk, void* value);
extern int    StackPop(Stack* stk, void* to);
extern int    StackPeek(Stack* const stk, void* to);
extern int    StackDistruct(Stack** stk);
extern int    MakeStack(Stack** stk, size_t size);
extern int    GetStackSize(Stack* stk);
