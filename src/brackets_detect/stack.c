#include "stack.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


#define ENSURE(expr, message) \
    if(!(expr)){\
        fprintf(stderr, "Fatal error: %s", message);\
        exit(1);\
    }\


struct stack_t
{
    int* data;
    int size;
    int capacity;
};

stack* make_stack(int capacity)
{
    stack* p = (stack*) malloc(sizeof(stack));
    ENSURE(p!= 0, "malloc stack failed");

    p->data = (int*) malloc(capacity * sizeof(int));
    ENSURE(p!= 0, "malloc data failed");

    p->size = 0;
    p->capacity = capacity;
    return p;
}

void destroy_stack(stack* stack)
{
    if (stack == 0) return;

    free(stack->data);
    free(stack);
}

void push(stack* stack, int item)
{
    assert(!is_full(stack));

    stack->data[stack->size++] = item;
}

void pop(stack* stack)
{
    assert(!is_empty(stack));

    --stack->size;
}
int top(const stack* stack)
{
    assert(!is_empty(stack));

    return stack->data[stack->size - 1];
}
int size(const stack* stack)
{
    return stack->size;
}

int capacity(const stack* stack)
{
    return stack->capacity;
}
int is_full(const stack* stack)
{
    return size(stack) == capacity(stack);
}
int is_empty(const stack* stack)
{
    return size(stack) == 0;
}
