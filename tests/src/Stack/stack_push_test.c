#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(stack_push, basic)
{
	t_stack	*stack;

	stack = create_stack(10);
	stack->push(stack, 0);
	stack->push(stack, -1);
	stack->push(stack, INT_MIN);
	stack->push(stack, INT_MAX);
	stack->push(stack, 3);
	EXPECT_EQ(5, stack->len);
	EXPECT_EQ(0, stack->stack[0]);
	EXPECT_EQ(-1, stack->stack[1]);
	EXPECT_EQ(INT_MIN, stack->stack[2]);
	EXPECT_EQ(INT_MAX, stack->stack[3]);
	EXPECT_EQ(3, stack->stack[4]);
	destroy_stack(stack);
}

TEST(stack_push, over_push)
{
	t_stack	*stack;

	stack = create_stack(3);
	stack->push(stack, 0);
	stack->push(stack, 0);
	stack->push(stack, 0);
	EXPECT_EQ(3, stack->len);
	stack->push(stack, 0);
	stack->push(stack, 0);
	stack->push(stack, 0);
	stack->push(stack, 0);
	EXPECT_EQ(3, stack->len);
	destroy_stack(stack);
}