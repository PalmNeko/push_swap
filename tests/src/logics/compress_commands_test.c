#include "../../submit/logics/_logics.h"
#include "command_list.h"
#include "tyctest.h"
#include <limits.h>

TEST(internal_compress_straight_rotate, compressed_success)
{
	t_command_list	*commands;
	t_command_list	*compressed;

	commands = create_command_list();
	commands->append(commands, "ra");
	commands->append(commands, "ra");
	commands->append(commands, "ra");
	compressed = compress_commands(commands, 3);
	ASSERT_NE(NULL, compressed);
	ASSERT_EQ(NULL, compressed->commands);
}

TEST(internal_compress_straight_rotate, compressed_failure)
{
	t_command_list	*commands;
	t_command_list	*compressed;

	commands = create_command_list();
	commands->append(commands, "ra");
	commands->append(commands, "ra");
	compressed = compress_commands(commands, 3);
	ASSERT_STREQ("ra", compressed->commands->content);
	ASSERT_STREQ("ra", compressed->commands->next->content);
	ASSERT_EQ(NULL, compressed->commands->next->next);
}
