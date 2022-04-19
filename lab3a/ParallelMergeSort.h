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
public:
	void sort();
	void merge_sort(int start, int end);
	ParallelMergeSort() = default;
};

template<typename T>
void ParallelMergeSort<T>::sort()
{
	merge_sort(0, MergeSort<T>::vec.size());
}
template<typename T>
void ParallelMergeSort<T>::merge_sort(int start, int end)
{
	if (end - start <= 1)
		return;
	int middle = (start + end) / 2;
	std::thread th(&ParallelMergeSort<T>::merge_sort, this, start, middle);
	merge_sort(middle, end);
	if (th.joinable())
		th.join();
	MergeSort<T>::merge(start, middle, end);
}
