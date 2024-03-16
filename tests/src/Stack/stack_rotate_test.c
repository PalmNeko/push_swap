#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(stack_rotate, basic)
{
	t_stack	*stack;

	stack = create_stack(4);
	stack->rotate(stack);
	stack->push(stack, 0);
	stack->rotate(stack);
	EXPECT_EQ(0, stack->stack[0]);
	stack->push(stack, 1);
	stack->rotate(stack);
	EXPECT_EQ(1, stack->stack[0]);
	stack->push(stack, 2);
	stack->rotate(stack);
	EXPECT_EQ(2, stack->stack[0]);
	destroy_stack(stack);
}