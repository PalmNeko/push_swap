#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(stack_pop, basic)
{
	t_stack	*stack;

	stack = create_stack(10);
	stack->push(stack, 1);
	stack->push(stack, 2);
	stack->push(stack, 3);
	EXPECT_EQ(3, stack->pop(stack));
	EXPECT_EQ(2, stack->pop(stack));
	EXPECT_EQ(1, stack->pop(stack));
	EXPECT_EQ(0, stack->len);
	destroy_stack(stack);
}