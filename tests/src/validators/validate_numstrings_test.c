
#include "validators.h"
#include "tyctest.h"
#include <limits.h>

TEST(validate_numstrings, basic_usage)
{
	EXPECT_TRUE(validate_numstrings((char *[]){"123"}, 1));
	EXPECT_TRUE(validate_numstrings((char *[]){"-123"}, 1));
	EXPECT_TRUE(validate_numstrings((char *[]){"0"}, 1));
	EXPECT_TRUE(validate_numstrings((char *[]){"1"}, 1));
	EXPECT_TRUE(validate_numstrings((char *[]){"-1"}, 1));
	EXPECT_FALSE(validate_numstrings((char *[]){"-0"}, 1));
	EXPECT_FALSE(validate_numstrings((char *[]){"a"}, 1));
	EXPECT_FALSE(validate_numstrings((char *[]){"O"}, 1));
	EXPECT_FALSE(validate_numstrings((char *[]){"123abc"}, 1));
	EXPECT_FALSE(validate_numstrings((char *[]){"123abc123"}, 1));
}

TEST(validate_numstrings, multi_values)
{
	EXPECT_TRUE(validate_numstrings((char *[]){"123", "-123"}, 2));
	EXPECT_TRUE(validate_numstrings((char *[]){"0", "123", "-123"}, 3));
	EXPECT_TRUE(validate_numstrings((char *[]){"-123", "123", "0"}, 3));
	EXPECT_TRUE(validate_numstrings((char *[]){"1", "-1"}, 2));
	EXPECT_TRUE(validate_numstrings((char *[]){"-1", "1"}, 2));
	EXPECT_FALSE(validate_numstrings((char *[]){"123", "123abc"}, 2));
	EXPECT_FALSE(validate_numstrings((char *[]){"123", "123abc123"}, 2));
}

TEST(validate_numstrings, error_check)
{
	EXPECT_TRUE(validate_numstrings((char *[]){"123", "-123"}, 0));
}
