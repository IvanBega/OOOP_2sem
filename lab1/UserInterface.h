#pragma once
#include <iostream>
#include <chrono>
#include "Date.h"
class UserInterface
{
public:
	template<typename T>
	static void Test(int count);
	template<typename T>
	static void QueueDemonstration(T q, int count);
	static void AddDateDemonstration(int count);
	static void SubtractDateDemonstration(int count);
	static void DateDiffDemonstration(int count);
	static void ConsoleQueueInterface();
	static void ConsoleDateInterface();
};
template<typename T>
void UserInterface::Test(int count)
{
	T q;
	auto start = std::chrono::high_resolution_clock::now();
	UserInterface::QueueDemonstration(q, count);
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "\nTook " << duration.count() << " microseconds";
}
template<typename T>
void UserInterface::QueueDemonstration(T q, int count)
{
	std::cout << "Pushing " << count << " elements:\n";
	for (int i = 0; i < count; i++)
	{
		// pushing
		Date temp;
		temp.fillWithRandom();
		std::srand(std::rand());
		int priority = rand() % 1000;
		q.push(temp, priority);
		temp.print();
		std::cout << ", priority " << priority << std::endl;
	}
	std::cout << "\n";
	// popping
	Date temp;
	std::cout << "Popping " << count << " elements:\n";
	for (int i = 0; i < count; i++)
	{
		temp = q.pop();
		temp.print();
		std::cout << "\n";
	}
}