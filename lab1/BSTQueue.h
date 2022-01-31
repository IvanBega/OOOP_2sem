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
		T data;
		int priority;
		Tree* lt;
		Tree* rt;
		Tree(T Data, int Priority, Tree* left = nullptr, Tree* right = nullptr)
		{
			data = Data; priority = Priority; lt = left; rt = right;
		}
	};
	Tree* head = nullptr;
	Tree* insert(Tree* current, T data, int priority);
	Tree* minTree();
	T delete_tree(Tree* current)
	{
		Tree* prev = nullptr;
		while (current->lt)
		{
			prev = current;
			current = current->lt;
		}
		if (prev && current->rt)
		{
			prev->lt = current->rt;
		}
		else
		{
			prev->lt = nullptr;
		}
		T data = current->data;
		delete current;
		return data;

	}
};

template<class T>
void BSTQueue<T>::push(T data, int priority)
{
	if (head == nullptr)
	{
		head = new Tree(data, priority);
	}
	else
		insert(head, data, priority);
}
template<class T>
T BSTQueue<T>::seek()
{
	return minTree()->data;
}
template<class T>
T BSTQueue<T>::pop()
{
	if (head->lt == nullptr)
	{
		Tree* temp = head;
		T data = temp->data;
		head = head->rt;
		delete temp;
		return data;
	}
	return delete_tree(head);
}
template<class T> typename
BSTQueue<T>::Tree* BSTQueue<T>::insert(Tree* current, T data, int priority)
{
	if (current == nullptr)
	{
		return new Tree(data, priority, nullptr, nullptr);
	}
	if (priority <= current->priority)
	{
		current->lt = insert(current->lt, data, priority);
	}
	else
	{
		current->rt = insert(current->rt, data, priority);
	}
	return current;
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