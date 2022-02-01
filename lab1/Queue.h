#pragma once
template<typename T>
class Queue
{
public:
	virtual void push(T data, int priority) = 0;
	virtual T peek() = 0;
	virtual T pop() = 0;
};