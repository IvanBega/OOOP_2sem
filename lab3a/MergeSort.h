#pragma once
#include <vector>
template<typename T>
class MergeSort
{

protected:
	std::vector<T> vec;
private:
	virtual void copyArray(std::vector<T>& copy, int start, int size) = 0;
public:
	virtual void setArray(std::vector<T> vec) = 0;
	virtual std::vector<T> getArray() = 0;
	virtual void sort() = 0;
	virtual void merge(int start, int middle, int end) = 0;
	virtual void merge_sort(int start, int end) = 0;
};

