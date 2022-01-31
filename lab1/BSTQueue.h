#pragma once
#include "Queue.h"
#include <iostream>
template<class T>
class BSTQueue : public Queue<T>
{
public:
	void push(T data, int priority);
	T seek();	
	T pop();
	~BSTQueue()
	{
		
	}
private:
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
	Tree* head = nullptr;
	void insert(T data, int priority);
	Tree* minTree();
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
T BSTQueue<T>::seek()
{
	return minTree()->data->seek();
}
template<class T>
T BSTQueue<T>::pop()
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