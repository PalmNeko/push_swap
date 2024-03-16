#include "command_list.h"
#include "tyctest.h"
#include <limits.h>

TEST(create_command_list, basic)
{
	t_command_list	*commands;

	commands = create_command_list();
	EXPECT_EQ(NULL, commands->commands);
	destroy_command_list(commands);
}
