#pragma once
#include "Queue.h"
#include "LinkedListQueue.h"
#include <iostream>
/// <summary>
/// Class which implements a priority queue based on binary search tree
/// </summary>
/// <typeparam name="T">data type of elements that stored in queue</typeparam>
template<class T>
class BSTQueue : public Queue<T>
{
public:
	void push(T data, int priority);
	T peek();	
	T pop();
	bool empty();
	~BSTQueue();
private:
	/// <summary>
	/// node of a tree which stores data and priority
	/// </summary>
	struct Tree
	{
		LinkedListQueue<T>* data;
		int priority;
		int size = 0;
		Tree* lt;
		Tree* rt;
		Tree(T Data, int Priority, Tree* left = nullptr, Tree* right = nullptr)
		{
			priority = Priority; lt = left; rt = right;
			data = new LinkedListQueue<T>;
			data->push(Data, priority);
			size++;
		}
		~Tree()
		{
			if (data != nullptr)
			{
				delete data;
			}
		}
	};
	/// <summary>
	/// head of a tree
	/// </summary>
	Tree* head = nullptr;
	void insert(T data, int priority);
	Tree* minTree();
	void deleteTree(Tree* node);
};

template<class T>
void BSTQueue<T>::push(T data, int priority)
{
	if (head == nullptr)
	{
		head = new Tree(data, priority);
	}
	else
		insert(data, priority);
}
template<class T>
T BSTQueue<T>::peek()
{
	if (!empty())
		return minTree()->data->peek();
	throw std::runtime_error("Queue is empty");
}
template<class T>
T BSTQueue<T>::pop()
{
	if (!empty())
	{
		if (head->lt == nullptr)
		{
			T data_to_pop = head->data->pop();
			head->size--;
			if (head->size > 0)
				return data_to_pop;

			Tree* temp = head;
			head = head->rt;
			delete temp;
			return data_to_pop;

		}
		Tree* prev = nullptr, * current = head;
		while (current->lt)
		{
			prev = current;
			current = current->lt;
		}
		T data_to_pop = current->data->pop();
		current->size--;
		if (current->size > 0)
			return data_to_pop;
		if (prev && current->rt)
		{
			prev->lt = current->rt;
		}
		else
		{
			prev->lt = nullptr;
		}

		delete current;
		return data_to_pop;
	}
	throw std::runtime_error("Queue is empty");
}
template<class T>
inline bool BSTQueue<T>::empty()
{
	return head == nullptr;
}
/// <summary>
/// deletes priority queue
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
inline BSTQueue<T>::~BSTQueue()
{
	deleteTree();
}
/// <summary>
/// inserts element into tree
/// </summary>
/// <param name="data">data to insert</param>
/// <param name="priority">priority of data</param>
template<class T> typename
void BSTQueue<T>::insert(T data, int priority)
{
	Tree* current = head;
	Tree* prev = nullptr;
	while (current != nullptr)
	{
		prev = current;
		if (priority > current->priority)
		{
			current = current->rt;
		}
		else
		{
			if (priority < current->priority)
			{
				current = current->lt;
			}
			else
			{
				if (priority == current->priority)
				{
					current->data->push(data, priority);
					current->size++;
					return;
				}
			}
		}
	}
	if (priority > prev->priority)
	{
		prev->rt = new Tree(data, priority, nullptr, nullptr);
	}
	else
	{
		prev->lt = new Tree(data, priority, nullptr, nullptr);
	}
}
/// <summary>
/// returns minimum node of a tree
/// </summary>
/// <returns></returns>
template<class T> typename
BSTQueue<T>::Tree* BSTQueue<T>::minTree()
{
	Tree* current = head;
	while (current->lt)
	{
		current = current->lt;
	}
	return current;
}
/// <summary>
/// recursively deletes tree
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="node">head of a tree</param>
template<class T>
inline void BSTQueue<T>::deleteTree(Tree* node)
{
	if (node == nullptr)
		return;

	deleteTree(node->lt);
	deleteTree(node->rt);

	delete node;
}
