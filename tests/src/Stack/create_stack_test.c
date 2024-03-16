#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(create_stack_test, basic)
{
	t_stack	*stack;

	stack = create_stack(10);
	ASSERT_NE(stack, NULL);
	EXPECT_EQ(0, stack->len);
	EXPECT_EQ(10, stack->max_len);
	EXPECT_NE(NULL, stack->stack);
	EXPECT_NE(NULL, stack->clone);
	EXPECT_NE(NULL, stack->pop);
	EXPECT_NE(NULL, stack->push);
	EXPECT_NE(NULL, stack->reverse_rotate);
	EXPECT_NE(NULL, stack->rotate);
	EXPECT_NE(NULL, stack->shift_down);
	EXPECT_NE(NULL, stack->shift_up);
	EXPECT_NE(NULL, stack->swap);
	destroy_stack(stack);
}