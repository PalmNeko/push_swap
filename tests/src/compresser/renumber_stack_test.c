#include "compresser.h"
#include "tyctest.h"
#include <limits.h>

TEST(renumber_stack, basic)
{
	t_stack	*stack;

	stack = create_stack(10);
	stack->push(stack, 10);
	stack->push(stack, 5);
	stack->push(stack, 12);
	stack->push(stack, -100);
	stack->push(stack, 123);
	if (renumber_stack(stack) != 0)
	{
		destroy_stack(stack);
		return ;
	}
	EXPECT_EQ(2, stack->stack[0]);
	EXPECT_EQ(1, stack->stack[1]);
	EXPECT_EQ(3, stack->stack[2]);
	EXPECT_EQ(0, stack->stack[3]);
	EXPECT_EQ(4, stack->stack[4]);
	destroy_stack(stack);
}