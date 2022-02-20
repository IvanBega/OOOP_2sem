#pragma once
/// <summary>
/// Base class which describes interface for priority queue
/// </summary>
/// <typeparam name="T">data type which stores priority queue</typeparam>
template<typename T>
class Queue
{
public:
	/// <summary>
	/// pushes data to priority queue with specified priority
	/// </summary>
	/// <param name="data">data to push</param>
	/// <param name="priority">data's priority</param>
	virtual void push(T data, int priority) = 0;
	/// <summary>
	/// returns element from priority queue with highest priority without removing it
	/// </summary>
	/// <returns>returns element with highest priority</returns>
	virtual T peek() = 0;
	/// <summary>
	/// returns and deletes element from priority queue with highest priority
	/// </summary>
	/// <returns>returns element with highest priority</returns>
	virtual T pop() = 0;
	/// <summary>
	/// checks whether priority queue is empty
	/// </summary>
	/// <returns>true if priority queue is empty, false otherwise</returns>
	virtual bool empty() = 0;
};