#include "validators.h"
#include "tyctest.h"
#include <limits.h>

TEST(validate_is_sorted, basic)
{
	t_stack	*stack;

	stack = create_stack(10);
	EXPECT_TRUE(validate_is_sorted(stack));
	stack->push(stack, 10);
	stack->push(stack, 9);
	EXPECT_TRUE(validate_is_sorted(stack));
	stack->push(stack, 9);
	EXPECT_TRUE(validate_is_sorted(stack));
	stack->push(stack, 10);
	EXPECT_FALSE(validate_is_sorted(stack));
	destroy_stack(stack);
}
