#include "command_list.h"
#include "tyctest.h"
#include <limits.h>

TEST(command_list_append, basic)
{
	t_command_list	*commands;

	commands = create_command_list();
	EXPECT_EQ(commands, commands->append(commands, "pa"));
	EXPECT_STREQ("pa", (char *)commands->commands->content);
	EXPECT_EQ(commands, commands->append(commands, "pb"));
	EXPECT_STREQ("pa", (char *)commands->commands->content);
	EXPECT_STREQ("pb", (char *)commands->commands->next->content);
	EXPECT_EQ(NULL, (char *)commands->commands->next->next);
	destroy_command_list(commands);
}
