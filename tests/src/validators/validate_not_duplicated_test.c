
#include "validators.h"
#include "tyctest.h"
#include <limits.h>

TEST(validate_not_duplicated, basic_usage)
{
	EXPECT_TRUE(validate_not_duplicated((int []){1, 3, 2}, 3));
	EXPECT_TRUE(validate_not_duplicated((int []){1, 3, 2, 4}, 4));
	EXPECT_TRUE(validate_not_duplicated((int []){-1, 3, 1, 4}, 4));
	EXPECT_FALSE(validate_not_duplicated((int []){1, 1}, 2));
	EXPECT_FALSE(validate_not_duplicated((int []){1, 2, 3, 3}, 4));
	EXPECT_FALSE(validate_not_duplicated((int []){1, 1, 3, 3}, 4));
	EXPECT_FALSE(validate_not_duplicated((int []){1, 1, 2, 3}, 4));
	EXPECT_FALSE(validate_not_duplicated((int []){1, 3, 3, 4, 5, 5, 7}, 4));
}

TEST(validate_not_duplicated, random)
{
	EXPECT_TRUE(validate_not_duplicated((int []){4, 5, -1, 2, 3}, 5));
	EXPECT_TRUE(validate_not_duplicated((int []){5, 0, 1, -1, 2}, 5));
	EXPECT_FALSE(validate_not_duplicated((int []){-1, 0, 1, -2, 1}, 5));
	EXPECT_FALSE(validate_not_duplicated((int []){0, -2, 1, 2, 2}, 5));
}

TEST(validate_not_duplicated, boundary_value)
{
	EXPECT_TRUE(validate_not_duplicated((int []){INT_MIN, INT_MAX}, 2));
	EXPECT_TRUE(validate_not_duplicated((int []){INT_MIN, INT_MAX - 1, INT_MAX}, 3));
	EXPECT_TRUE(validate_not_duplicated((int []){INT_MIN + 2, INT_MIN + 1, INT_MIN}, 3));
	EXPECT_FALSE(validate_not_duplicated((int []){INT_MIN, INT_MAX, INT_MAX}, 3));
	EXPECT_FALSE(validate_not_duplicated((int []){INT_MIN, INT_MIN, INT_MAX}, 3));
}

TEST(validate_not_duplicated, error_check)
{
	EXPECT_FALSE(validate_not_duplicated((int []){0, 1}, 0));
}
