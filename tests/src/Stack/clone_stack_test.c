#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(clone_stack, basic)
{
	t_stack	*stack;
	t_stack	*cloned;

	stack = create_stack(12);
	stack->push(stack, 3);
	stack->push(stack, 6);
	stack->push(stack, 8);
	stack->push(stack, 12);
	cloned = stack->clone(stack);
	ASSERT_NE(NULL, cloned);
	ASSERT_NE(stack, cloned);
	ASSERT_NE(stack->stack, cloned->stack);
	EXPECT_EQ(stack->stack[0], cloned->stack[0]);
	EXPECT_EQ(stack->stack[1], cloned->stack[1]);
	EXPECT_EQ(stack->stack[2], cloned->stack[2]);
	EXPECT_EQ(stack->stack[3], cloned->stack[3]);
	EXPECT_EQ(stack->len, cloned->len);
	EXPECT_EQ(stack->max_len, cloned->max_len);
	EXPECT_EQ(stack->len, cloned->len);
	EXPECT_EQ(stack->push, cloned->push);
	EXPECT_EQ(stack->swap, cloned->swap);
	EXPECT_EQ(stack->pop, cloned->pop);
	EXPECT_EQ(stack->rotate, cloned->rotate);
	EXPECT_EQ(stack->shift_up, cloned->shift_up);
	EXPECT_EQ(stack->reverse_rotate, cloned->reverse_rotate);
	EXPECT_EQ(stack->shift_down, cloned->shift_down);
	EXPECT_EQ(stack->clone, cloned->clone);
	destroy_stack(stack);
	destroy_stack(cloned);
}