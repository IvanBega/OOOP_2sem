#pragma once
#include "Queue.h"
template<class T>
class LinkedListQueue : public Queue<T>
{
public:
	void push(T data, int priority);
	T pop();
	T seek();
	~LinkedListQueue()
	{
			
	}
private:
	struct Node
	{
		T data;
		Node* next;
		int priority;
	};
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
	Node* temp = head;
	T data = head->data;
	head = head->next;
	delete temp;
	return data;
}
template<class T>
T LinkedListQueue<T>::seek()
{
	return head->data;
}