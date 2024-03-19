#include "compresser.h"
#include "command_list.h"
#include "tyctest.h"
#include <limits.h>

TEST(compress_straight_rotate, compressed_success)
{
	t_command_list	*commands;
	t_command_list	*compressed;

	commands = create_command_list();
	commands->append(commands, "ra");
	commands->append(commands, "ra");
	commands->append(commands, "ra");
	compressed = compress_straight_rotate(commands, 3);
	ASSERT_NE(NULL, compressed);
	ASSERT_EQ(NULL, compressed->commands);
}

TEST(compress_straight_rotate, compressed_failure)
{
	t_command_list	*commands;
	t_command_list	*compressed;

	commands = create_command_list();
	commands->append(commands, "ra");
	commands->append(commands, "ra");
	commands->append(commands, "sa");
	compressed = compress_straight_rotate(commands, 3);
	ASSERT_STREQ("ra", compressed->commands->content);
	ASSERT_STREQ("ra", compressed->commands->next->content);
	ASSERT_STREQ("sa", compressed->commands->next->next->content);
	ASSERT_EQ(NULL, compressed->commands->next->next->next);
}
