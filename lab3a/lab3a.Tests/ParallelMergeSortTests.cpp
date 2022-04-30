#pragma once
#include "pch.h"
#include <vector>
#include "../ParallelMergeSort.h"
#include "../Utils.h"
TEST(ParallelMergeSort, NoThrowIfVectorIsEmpty)
{
	std::vector<int> v{};
	ParallelMergeSort<int> sorter;
	sorter.setArray(v);
	EXPECT_NO_THROW(sorter.sort());
}

TEST(ParallelMergeSort, SortOneElement)
{
	std::vector<int> v{ 1 };
	ParallelMergeSort<int> sorter;
	sorter.setArray(v);
	sorter.sort();
	std::vector<int> actual = sorter.getArray();

	EXPECT_EQ(v.size(), 1);
	EXPECT_EQ(actual.size(), 1);
	EXPECT_EQ(actual[0], 1);
}

TEST(ParallelMergeSort, SortSameElements)
{
	std::vector<int> v{ 1, 1, 1, 1, 1 };
	ParallelMergeSort<int> sorter;
	sorter.setArray(v);
	sorter.sort();
	std::vector<int> actual = sorter.getArray();

	EXPECT_EQ(v.size(), 5);
	EXPECT_EQ(actual.size(), 5);

	for (int i = 0; i < 5; i++)
		EXPECT_EQ(1, actual[0]);
}

TEST(ParallelMergeSort, SortDifferentElements)
{
	std::vector<int> toSort{ 18, 62, 31, -7, 4, 25 };
	std::vector<int> expected{ -7, 4, 18, 25, 31, 62 };
	ParallelMergeSort<int> sorter;
	sorter.setArray(toSort);
	sorter.sort();
	std::vector<int> actual = sorter.getArray();

	EXPECT_EQ(actual.size(), 6);

	EXPECT_TRUE(actual == expected);
	expected[0] = 0;
	EXPECT_FALSE(actual == expected);
}

TEST(ParallelMergeSort, SortRandomElements)
{
	int vector_size = 100;
	std::vector<int> randomVector = Utils::randVec(0, 1000000, vector_size);

	ParallelMergeSort<int> sorter;
	sorter.setArray(randomVector);
	sorter.sort();

	std::vector<int> actual = sorter.getArray();
	EXPECT_EQ(actual.size(), vector_size);

	for (int i = 0; i < vector_size - 1; i++)
	{
		EXPECT_TRUE(actual[i] <= actual[i + 1]);
	}
}