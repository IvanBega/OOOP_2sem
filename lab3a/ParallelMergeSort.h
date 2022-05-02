#pragma once
#include <vector>
#include <thread>
#include "MergeSort.h"
template<typename T>
class ParallelMergeSort : public MergeSort<T>
{
private:
	int maximumThreadCount = std::thread::hardware_concurrency();
	int currentThreads = 0;
	void merge_sort(int start, int end);
public:
	void sort();
};
/// <summary>
/// Main method for sorting an array
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void ParallelMergeSort<T>::sort()
{
	merge_sort(0, MergeSort<T>::vec.size());
}
/// <summary>
/// Parallel Merge Sort method
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="start"></param>
/// <param name="end"></param>
template<typename T>
void ParallelMergeSort<T>::merge_sort(int start, int end)
{
	if (end - start <= 1)
		return;
	int middle = (start + end) / 2;
	if (currentThreads < maximumThreadCount)
	{
		std::thread th(&ParallelMergeSort<T>::merge_sort, this, start, middle);
		currentThreads++;
		merge_sort(middle, end);
		if (th.joinable())
		{
			th.join();
			currentThreads--;
		}
	}
	else
	{
		merge_sort(start, middle);
		merge_sort(middle, end);
	}
	MergeSort<T>::merge(start, middle, end);
}
