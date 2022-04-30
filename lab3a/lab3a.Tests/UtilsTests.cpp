#include "pch.h"
#include <vector>
#include "../Utils.h"
TEST(UtilsTest, RandomIntegerTest)
{
	for (int i = 0; i < 100; i++)
	{
		int actual = Utils::randInt(0, 10);
		EXPECT_TRUE(actual >= 0 && actual <= 10);
	}
}

TEST(UtilsTest, RandomVectorTest)
{
	std::vector<int> actual = Utils::randVec(0, 10, 100);
	EXPECT_EQ(actual.size(), 100);

	for (int i = 0; i < 100; i++)
	{
		EXPECT_TRUE(actual[i] >= 0 && actual[i] <= 10);
	}
}