#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "ParallelMergeSort.h"
#include "ClassicMergeSort.h"
#include "Utils.h"
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
public:
	void TestParallel(std::vector<int> range);
	void TestClassic(std::vector<int> range);
};
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
		MergeTest(arraySize);
	}
}
template<class T>
void CompareSorts<T>::MergeTest(int arraySize)
{
	
	std::vector<int> a = Utils::randVec(minValue, maxValue, arraySize);
	sorter->setArray(a);


	auto start = std::chrono::high_resolution_clock::now();

	sorter->sort();

	auto stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

	std::cout << "Sorted " << arraySize << " elements in " <<  duration.count() << " microseconds\n";
}
