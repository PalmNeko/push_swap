#include "compresser.h"
#include "tyctest.h"
#include <limits.h>

TEST(halfcut_straight_rotate, basic)
{
	t_command_list	*commands;
	t_command_list	*result;

	commands = create_command_list();
	commands->append(commands, "ra");
	commands->append(commands, "ra");
	result = halfcut_straight_rotate(commands, 3);
	EXPECT_NE(result, commands);
	EXPECT_STREQ("rra", result->commands->content);
	EXPECT_EQ(NULL, result->commands->next);
	destroy_command_list(result);
	commands->append(commands, "ra");
	result = halfcut_straight_rotate(commands, 3);
	EXPECT_STREQ("rra", result->commands->content);
	EXPECT_STREQ("ra", result->commands->next->content);
	EXPECT_EQ(NULL, result->commands->next->next);
	destroy_command_list(result);
	destroy_command_list(commands);
}