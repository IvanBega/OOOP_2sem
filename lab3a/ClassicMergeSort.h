#pragma once
#include "MergeSort.h"
#include <vector>
template <typename T>
class ClassicMergeSort : public MergeSort<T>
{
private:
	//std::vector<T> array;
	void copyArray(std::vector<T>& copy, int start, int size);
public:
	void setArray(std::vector<T> array);
	std::vector<T> getArray();
	void sort();
	void merge(int start, int middle, int end);
	void merge_sort(int start, int end);
	ClassicMergeSort() = default;
};

template<typename T>
void ClassicMergeSort<T>::copyArray(std::vector<T>& copy, int start, int size)
{
	copy.clear();
	for (unsigned int i = 0; i < size; i++)
	{
		copy.push_back(array[start + i]);
	}
}

template<typename T>
inline void ClassicMergeSort<T>::setArray(std::vector<T> array)
{
	this->array = std::move(array);
}

template<typename T>
inline std::vector<T> ClassicMergeSort<T>::getArray()
{
	return this->array;
}

template<typename T>
void ClassicMergeSort<T>::sort()
{
	merge_sort(0, array.size());
}

template<typename T>
void ClassicMergeSort<T>::merge(int start, int middle, int end)
{
	int leftIndex = middle - start;
	int rightIndex = end - middle;
	int i = 0, j = 0, k = start;
	std::vector<T> leftPart, rightPart;
	copyArray(leftPart, start, leftIndex);
	copyArray(rightPart, middle, rightIndex);

	while (i < leftIndex && j < rightIndex)
	{
		if (leftPart[i] <= rightPart[j])
		{
			array[k] = leftPart[i];
			i++;
		}
		else
		{
			array[k] = rightPart[j];
			j++;
		}
		k++;
	}
	for (; i < leftIndex; i++, k++)
		array[k] = leftPart[i];
	for (; j < rightIndex; j++, k++)
		array[k] = rightPart[j];

}

template<typename T>
void ClassicMergeSort<T>::merge_sort(int start, int end)
{
	if (end - start <= 1)
		return;
	int middle = (start + end) / 2;
	merge_sort(start, middle);
	merge_sort(middle, end);
	merge(start, middle, end);
}