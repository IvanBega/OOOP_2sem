#pragma once
#include "Queue.h"
#include <vector>

template<class T>
class BinaryHeapQueue : public Queue<T>
{
public:
	void push(T data, int priority);
	T seek();
	T pop();
private:
	struct elem
	{
		T data;
		int priority;
		elem(T Data, int Priority)
		{
			data = Data; priority = Priority;
		}
	};
	std::vector<elem> arr;
	int size = -1;
	int parentIndex(int i);
	int leftChildIndex(int i);
	int rightChildIndex(int i);
	void heapify(int i);
	void moveDown(int i);
};

template<class T>
void BinaryHeapQueue<T>::push(T data, int priority)
{
	size += 1;
	elem temp(data, priority);
	arr.push_back(temp);

	heapify(size);
}
template<class T>
T BinaryHeapQueue<T>::seek()
{
	return arr[0].data;
}
template<class T>
T BinaryHeapQueue<T>::pop()
{
	T data = arr[0].data;
	std::swap(arr[0], arr[size]);
	arr.pop_back();
	size--;

	moveDown(0);
	return data;
}
template<class T>
int BinaryHeapQueue<T>::parentIndex(int i)
{
	return (i - 1) / 2;
}
template<class T>
int BinaryHeapQueue<T>::leftChildIndex(int i)
{

	return 2 * i + 1;
}
template<class T>
int BinaryHeapQueue<T>::rightChildIndex(int i)
{
	return 2 * i + 2;
}
template<class T>
void BinaryHeapQueue<T>::heapify(int i)
{
	while (i > 0 && arr[parentIndex(i)].priority > arr[i].priority) // replace > to >=
	{
		std::swap(arr[parentIndex(i)], arr[i]);
		i = parentIndex(i);
	}
}
template<class T>
void BinaryHeapQueue<T>::moveDown(int i)
{
	int max = i;
	int l = leftChildIndex(i);
	if (l <= size && arr[l].priority < arr[max].priority) // replace < to >=
	{
		max = l;
	}

	int r = rightChildIndex(i);
	if (r <= size && arr[r].priority < arr[max].priority) // replaced < to <=
	{
		max = r;
	}

	if (i != max)
	{
		std::swap(arr[i], arr[max]);
		moveDown(max);
	}
}