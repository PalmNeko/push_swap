#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(stack_get_head, basic)
{
	t_stack	*stack;

	stack = create_stack(10);
	EXPECT_EQ(NULL, stack->get_head(stack, 0));
	stack->push(stack, 1);
	EXPECT_EQ(1, *stack->get_head(stack, 0));
	stack->push(stack, 2);
	EXPECT_EQ(1, *stack->get_head(stack, 1));
	stack->push(stack, 3);
	EXPECT_EQ(1, *stack->get_head(stack, 2));
	EXPECT_EQ(NULL, stack->get_head(stack, 3));
	destroy_stack(stack);
}