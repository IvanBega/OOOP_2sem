#pragma once
#include <vector>
/// <summary>
/// Abstract class which designed for Merge Sort
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T>
class MergeSort
{

protected:
	std::vector<T> vec;
	void copyArray(std::vector<T>& copy, int start, int amount);
	void merge(int start, int middle, int end);
	virtual void merge_sort(int start, int end) = 0;
public:
	void setArray(std::vector<T> vec);
	std::vector<T> getArray();
	virtual void sort()= 0;
	MergeSort();
	~MergeSort();
};
/// <summary>
/// Copies elements to vector "copy" from main array vec
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="copy"></param>
/// <param name="start"></param>
/// <param name="amount"></param>
template<typename T>
void MergeSort<T>::copyArray(std::vector<T>& copy, int start, int amount)
{
	copy.clear();
	for (unsigned int i = 0; i < amount; i++)
	{
		copy.push_back(vec[start + i]);
	}
}
/// <summary>
/// Sets an array which will be sorted
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="vec"></param>
template<typename T>
void MergeSort<T>::setArray(std::vector<T> vec)
{
	this->vec = std::move(vec);
}
/// <summary>
/// Returns sorted array
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T>
std::vector<T> MergeSort<T>::getArray()
{
	return this->vec;
}
template<typename T>
inline MergeSort<T>::MergeSort()
{
}
template<typename T>
inline MergeSort<T>::~MergeSort()
{
}
/// <summary>
/// Merges two parts of arrays into one
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="start"></param>
/// <param name="middle"></param>
/// <param name="end"></param>
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
