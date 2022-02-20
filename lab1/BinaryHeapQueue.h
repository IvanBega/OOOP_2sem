#pragma once
#include "Queue.h"
#include <vector>
/// <summary>
/// Class which implements a priority queue based on binary heap
/// </summary>
/// <typeparam name="T">data type of elements that stored in queue</typeparam>
template<class T>
class BinaryHeapQueue : public Queue<T>
{
public:
	void push(T data, int priority);
	T peek();
	T pop();
	bool empty();
	~BinaryHeapQueue();
private:
	/// <summary>
	/// stores data and priority together
	/// </summary>
	struct elem
	{
		T data;
		int priority;
		elem(T Data, int Priority)
		{
			data = Data; priority = Priority;
		}
	};
	/// <summary>
	/// vector in which elements of queue are stored
	/// </summary>
	std::vector<elem> arr;
	/// <summary>
	/// size of queue
	/// </summary>
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
T BinaryHeapQueue<T>::peek()
{
	if (!empty())
		return arr[0].data;
	throw std::runtime_error("Queue is empty");
}
template<class T>
T BinaryHeapQueue<T>::pop()
{
	if (!empty())
	{
		T data = arr[0].data;
		std::swap(arr[0], arr[size]);
		arr.pop_back();
		size--;

		moveDown(0);
		return data;
	}
	throw std::runtime_error("Queue is empty");
}
template<class T>
inline bool BinaryHeapQueue<T>::empty()
{
	return size == -1;
}
/// <summary>
/// destroys queue and its elements
/// </summary>
/// <typeparam name="T">data type of elements that stored in queue</typeparam>
template<class T>
BinaryHeapQueue<T>::~BinaryHeapQueue()
{
	{
		for (auto a : arr)
			delete a;
		arr.clear();
	}
}
/// <summary>
/// returns index of a parent
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="i">index of current element</param>
/// <returns>returns index of a parent</returns>
template<class T>
int BinaryHeapQueue<T>::parentIndex(int i)
{
	return (i - 1) / 2;
}
/// <summary>
/// returns index of left child
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="i">index of current element</param>
/// <returns>returns index of left child</returns>
template<class T>
int BinaryHeapQueue<T>::leftChildIndex(int i)
{

	return 2 * i + 1;
}
/// <summary>
/// returns index of right child
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="i">index of current element</param>
/// <returns>returns index of right child</returns>
template<class T>
int BinaryHeapQueue<T>::rightChildIndex(int i)
{
	return 2 * i + 2;
}
/// <summary>
/// restores property of binary heap
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="i"></param>
template<class T>
void BinaryHeapQueue<T>::heapify(int i)
{
	while (i > 0 && arr[parentIndex(i)].priority > arr[i].priority)
	{
		std::swap(arr[parentIndex(i)], arr[i]);
		i = parentIndex(i);
	}
}
/// <summary>
/// shifts down the node to maintain the heap priority
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="i"></param>
template<class T>
void BinaryHeapQueue<T>::moveDown(int i)
{
	int max = i;
	int l = leftChildIndex(i);
	if (l <= size && arr[l].priority < arr[max].priority)
	{
		max = l;
	}

	int r = rightChildIndex(i);
	if (r <= size && arr[r].priority < arr[max].priority)
	{
		max = r;
	}

	if (i != max)
	{
		std::swap(arr[i], arr[max]);
		moveDown(max);
	}
}