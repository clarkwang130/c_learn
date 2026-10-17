
#ifndef STACK_H
#define STACK_H

typedef struct stack_t stack;

stack* make_stack(int capacity);
void destroy_stack(stack* stack);

void push(stack* stack, int item);
void pop(stack* stack);

int top(const stack* stack);
int size(const stack* stack);
int capacity(const stack* stack);

int is_full(const stack*);
int is_empty(const stack*);


#endif // end STACK_H
