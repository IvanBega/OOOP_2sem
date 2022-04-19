#pragma once
#include "MergeSort.h"
#include <vector>
template <typename T>
class ClassicMergeSort : public MergeSort<T>
{
public:
	void sort();
	void merge_sort(int start, int end);
	ClassicMergeSort() = default;
};
template<typename T>
void ClassicMergeSort<T>::sort()
{
	merge_sort(0, MergeSort<T>::vec.size());
}
template<typename T>
void ClassicMergeSort<T>::merge_sort(int start, int end)
{
	if (end - start <= 1)
		return;
	int middle = (start + end) / 2;
	merge_sort(start, middle);
	merge_sort(middle, end);
	MergeSort<T>::merge(start, middle, end);
}