#pragma once
#include "MergeSort.h"
#include <vector>
template <typename T>
class ClassicSortingStrategy : public SortingStrategy<T>
{
private:
	void merge_sort(int start, int end);
public:
	void sort();
};
/// <summary>
/// Main method for sorting an array
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
void ClassicSortingStrategy<T>::sort()
{
	merge_sort(0, SortingStrategy<T>::vec.size());
}
/// <summary>
/// Sequential Merge Sort method
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="start"></param>
/// <param name="end"></param>
template<typename T>
void ClassicSortingStrategy<T>::merge_sort(int start, int end)
{
	if (end - start <= 1)
		return;
	int middle = (start + end) / 2;
	merge_sort(start, middle);
	merge_sort(middle, end);
	SortingStrategy<T>::merge(start, middle, end);
}