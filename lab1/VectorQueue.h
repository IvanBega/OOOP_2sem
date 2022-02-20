#pragma once
#include <vector>
#include "Queue.h"
/// <summary>
/// Class which implements priority queue based on vector
/// </summary>
/// <typeparam name="T">data type of elements that stored in queue</typeparam>
template <class T>
class VectorQueue : public Queue<T>
{
public:
	void push(T data, int priority)
	{
		elem temp(data, priority);
		if (arr.empty())
		{
			arr.push_back(temp);
			return;
		}
		int low = 0, high = arr.size() - 1, mid = (low + high) / 2;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (priority < arr[mid].priority)
			{
				low = mid + 1;
				mid = low;
			}
			else
			{
				high = mid - 1;
				mid = high + 1;
			}
		}
		auto it = arr.begin() + mid;
		arr.insert(it, temp);
	}
	T pop()
	{
		if (!empty())
		{
			elem temp = arr.back();
			arr.pop_back();
			return temp.data;
		}
		throw std::runtime_error("Queue is empty");
	}
	T peek()
	{
		if (!empty())
		{
			elem last = arr.back();
			return last.data;
		}
		throw std::runtime_error("Queue is empty");
	}
	bool empty();
	~VectorQueue();
private:
	/// <summary>
	/// stores data and priority of an element
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
	/// vector in which elements are stored
	/// </summary>
	std::vector<elem> arr;
};

template<class T>
inline bool VectorQueue<T>::empty()
{
	return arr.empty();
}
/// <summary>
/// deletes priority queue
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
inline VectorQueue<T>::~VectorQueue()
{
	for (auto a : arr)
		delete a;
	arr.clear();
}
