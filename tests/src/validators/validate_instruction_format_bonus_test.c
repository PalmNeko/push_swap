#include "tyctest.h"
#include "validators_bonus.h"
#include <limits.h>

TEST(validate_instruction_format, basic)
{
	EXPECT_TRUE(validate_instruction_format("pa"));
	EXPECT_TRUE(validate_instruction_format("pb"));
	EXPECT_TRUE(validate_instruction_format("sa"));
	EXPECT_TRUE(validate_instruction_format("sb"));
	EXPECT_TRUE(validate_instruction_format("ss"));
	EXPECT_TRUE(validate_instruction_format("ra"));
	EXPECT_TRUE(validate_instruction_format("rb"));
	EXPECT_TRUE(validate_instruction_format("rr"));
	EXPECT_TRUE(validate_instruction_format("rra"));
	EXPECT_TRUE(validate_instruction_format("rrb"));
	EXPECT_TRUE(validate_instruction_format("rrr"));
	EXPECT_FALSE(validate_instruction_format("rrra"));
	EXPECT_FALSE(validate_instruction_format("rab"));
	EXPECT_FALSE(validate_instruction_format(""));
}