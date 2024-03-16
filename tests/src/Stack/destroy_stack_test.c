#include "stack.h"
#include "tyctest.h"
#include <limits.h>

TEST(destroy_stack, basic)
{
	t_stack	*stack;

	stack = create_stack(10);
	destroy_stack(stack);
}