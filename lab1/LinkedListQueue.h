#pragma once
#include "Queue.h"
/// <summary>
/// Class which implements priority queue based on linked list
/// </summary>
/// <typeparam name="T">data type of elements that stored in queue</typeparam>
template<class T>
class LinkedListQueue : public Queue<T>
{
public:
	void push(T data, int priority);
	T pop();
	T peek();
	bool empty();
	~LinkedListQueue();
private:
	/// <summary>
	/// node of linked list
	/// </summary>
	struct Node
	{
		T data;
		Node* next = nullptr;
		int priority = 0;
	};
	/// <summary>
	/// head of linked list
	/// </summary>
	Node* head = nullptr;
};

template<class T>
void LinkedListQueue<T>::push(T data, int priority)
{
	Node* current = head;
	Node* temp = new Node();
	temp->data = data;
	temp->priority = priority;
	if (head == nullptr)
	{
		temp->next = nullptr;
		head = temp;
		return;
	}
	if (priority < head->priority)
	{
		temp->next = head;
		head = temp;
	}
	else
	{
		while (current->next != nullptr && current->next->priority <= priority)
		{
			current = current->next;
		}

		temp->next = current->next;
		current->next = temp;
	}
}
template<class T>
T LinkedListQueue<T>::pop()
{
	if (!empty())
	{
		Node* temp = head;
		T data = head->data;
		head = head->next;
		delete temp;
		return data;
	}
	throw std::runtime_error("Queue is empty");
}
template<class T>
T LinkedListQueue<T>::peek()
{
	if (!empty())
		return head->data;
	throw std::runtime_error("Queue is empty");
}

template<class T>
inline bool LinkedListQueue<T>::empty()
{
	return head == nullptr;
}
/// <summary>
/// deletes priority queue
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
inline LinkedListQueue<T>::~LinkedListQueue()
{
	Node* temp = head;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}
