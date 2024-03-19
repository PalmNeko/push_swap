#include "command_list.h"
#include "tyctest.h"
#include <limits.h>

TEST(command_list_append_repeatedly, basic)
{
	t_command_list	*commands;

	commands = create_command_list();
	EXPECT_EQ(commands, commands->append_repeatedly(commands, "pa", 0));
	EXPECT_EQ(NULL, (char *)commands->commands);
	EXPECT_EQ(commands, commands->append_repeatedly(commands, "pa", 3));
	EXPECT_STREQ("pa", (char *)commands->commands->content);
	EXPECT_STREQ("pa", (char *)commands->commands->next->content);
	EXPECT_STREQ("pa", (char *)commands->commands->next->next->content);
	EXPECT_EQ(NULL, (char *)commands->commands->next->next->next);
	destroy_command_list(commands);
}