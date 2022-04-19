#pragma once
#include <vector>
template<typename T>
class MergeSort
{

protected:
	std::vector<T> vec;
	void copyArray(std::vector<T>& copy, int start, int size);
private:
	
public:
	void setArray(std::vector<T> vec);
	std::vector<T> getArray();
	virtual void sort()= 0;
	void merge(int start, int middle, int end);
	virtual void merge_sort(int start, int end) = 0;
};
template<typename T>
void MergeSort<T>::copyArray(std::vector<T>& copy, int start, int size)
{
	copy.clear();
	for (unsigned int i = 0; i < size; i++)
	{
		copy.push_back(vec[start + i]);
	}
}
template<typename T>
void MergeSort<T>::setArray(std::vector<T> vec)
{
	this->vec = std::move(vec);
}

template<typename T>
std::vector<T> MergeSort<T>::getArray()
{
	return this->vec;
}
template<typename T>
void MergeSort<T>::merge(int start, int middle, int end)
{
	int leftIndex = middle - start;
	int rightIndex = end - middle;
	int i = 0, j = 0, k = start;
	std::vector<T> leftPart, rightPart;
	MergeSort<T>::copyArray(leftPart, start, leftIndex);
	MergeSort<T>::copyArray(rightPart, middle, rightIndex);

	while (i < leftIndex && j < rightIndex)
	{
		if (leftPart[i] <= rightPart[j])
		{
			MergeSort<T>::vec[k] = leftPart[i];
			i++;
		}
		else
		{
			MergeSort<T>::vec[k] = rightPart[j];
			j++;
		}
		k++;
	}
	for (; i < leftIndex; i++, k++)
		MergeSort<T>::vec[k] = leftPart[i];
	for (; j < rightIndex; j++, k++)
		MergeSort<T>::vec[k] = rightPart[j];

}
