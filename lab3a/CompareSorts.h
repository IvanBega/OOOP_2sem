#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "ParallelMergeSort.h"
#include "ClassicMergeSort.h"
#include "Utils.h"
#include <stdexcept>
/// <summary>
/// Class which compares two sorts for amount of elements in range array.
/// Makes testsCount calculations and prints average result.
/// Maximum size of tested array is limited to 2,000,000 elements.
/// If testsCount is not specified, it is set to 10 by default.
/// In order to avoid overflow, testsCount is limited by 50.
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class CompareSorts
{
private:
	std::vector<int> range;
	MergeSort<T>* sorter = nullptr;
	void MergeSort();
	void MergeTest(int arraySize);
	int minValue = 0;
	int maxValue = 10000;
	int testsCount = 10;
public:
	~CompareSorts();
	CompareSorts();
	CompareSorts(int testsCount);
	void TestParallel(std::vector<int> range);
	void TestClassic(std::vector<int> range);
};
template<class T>
CompareSorts<T>::~CompareSorts()
{
}
template<class T>
CompareSorts<T>::CompareSorts()
{
}
template<class T>
CompareSorts<T>::CompareSorts(int testsCount) : testsCount(testsCount)
{
	if (testsCount > 50 || testsCount < 1)
	{
		throw std::out_of_range("testsCount was out of range");
	}
}
template<class T>
void CompareSorts<T>::TestParallel(std::vector<int> range)
{
	sorter = new ParallelMergeSort<T>();
	this->range = std::move(range);
	MergeSort();
}
template<class T>
void CompareSorts<T>::TestClassic(std::vector<int> range)
{
	sorter = new ClassicMergeSort<T>();
	this->range = std::move(range);
	MergeSort();
}
template<class T>
void CompareSorts<T>::MergeSort()
{
	for (int arraySize : range)
	{
		if (arraySize < 2000000 && arraySize > 0)
			MergeTest(arraySize);
		else
			throw std::out_of_range("arraySize was out of range");
	}
}
template<class T>
void CompareSorts<T>::MergeTest(int arraySize)
{
	
	std::vector<int> a = Utils::randVec(minValue, maxValue, arraySize);
	int total_time = 0;
	for (int i = 0; i < testsCount; i++)
	{
		sorter->setArray(a);

		auto start = std::chrono::high_resolution_clock::now();

		sorter->sort();

		auto stop = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
		total_time += duration.count();
	}
	int average_time = total_time / testsCount;

	std::cout << "Sorted " << arraySize << " elements in " <<  average_time << " microseconds\n";
}
