#pragma once
#include "MergeSort.h"
#include <vector>
template<class T>
class Sorter
{
private:
	SortingStrategy<T>* strategy;
public:
	~Sorter();
	Sorter(SortingStrategy<T>* strategy = nullptr);
	void set_strategy(SortingStrategy<T>* strategy);
	void sort();
	void setArray(std::vector<T> vec);
	std::vector<T> getArray();
};

template<class T>
Sorter<T>::~Sorter()
{
	delete this->strategy;
}

template<class T>
Sorter<T>::Sorter(SortingStrategy<T>* strategy)
{
	this->strategy = strategy;
}

template<class T>
void Sorter<T>::set_strategy(SortingStrategy<T>* strategy)
{
	this->strategy = strategy;
}

template<class T>
inline void Sorter<T>::sort()
{
	strategy->sort();
}

template<class T>
void Sorter<T>::setArray(std::vector<T> vec)
{
	strategy->setArray(vec);
}

template<class T>
std::vector<T> Sorter<T>::getArray()
{
	return strategy->getArray();
}
