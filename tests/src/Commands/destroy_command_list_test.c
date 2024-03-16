#include "command_list.h"
#include "tyctest.h"
#include <limits.h>

TEST(destroy_command_list, basic)
{
	t_command_list	*commands;

	commands = create_command_list();
	destroy_command_list(commands);
}