#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(stack_swap, basic)
{
	t_stack	*stack;

	stack = create_stack(3);
	stack->push(stack, 1);
	stack->swap(stack);
	EXPECT_EQ(1, stack->stack[0]);
	stack->push(stack, 2);
	stack->push(stack, 3);
	stack->swap(stack);
	EXPECT_EQ(1, stack->stack[0]);
	EXPECT_EQ(3, stack->stack[1]);
	EXPECT_EQ(2, stack->stack[2]);
	EXPECT_EQ(3, stack->len);
	destroy_stack(stack);
}