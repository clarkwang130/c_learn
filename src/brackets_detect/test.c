#include <assert.h>
#include <stdbool.h>
#include "stack.h"
#include <stdio.h>

static void test_initial_state(void)
{
	stack* values = make_stack(3);

	assert(values != 0);
	assert(capacity(values) == 3);
	assert(size(values) == 0);
	assert(is_empty(values));
	assert(!is_full(values));

	destroy_stack(values);
}

static void test_push_pop_lifo(void)
{
	stack* values = make_stack(3);

	push(values, 10);
	push(values, -20);
	push(values, 30);

	assert(size(values) == 3);
	assert(is_full(values));
	assert(top(values) == 30);

	pop(values);
	assert(top(values) == -20);
	assert(size(values) == 2);

	pop(values);
	assert(top(values) == 10);
	pop(values);
	assert(size(values) == 0);
	assert(is_empty(values));

	destroy_stack(values);
}

int main(void)
{
	test_initial_state();
	test_push_pop_lifo();
    printf("All tests passed!\n");
	return 0;
}
