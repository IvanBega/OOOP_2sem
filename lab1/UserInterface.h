#pragma once
#include <iostream>
#include <chrono>
#include "DateTime.h"
#include "Time.h"
#include "Date.h"
#include "Utils.h"
class UserInterface
{
public:
	template<typename T>
	static void Test(int count);
	template<typename T>
	static void QueueDemonstration(T q, int count);
	//static void AddDateDemonstration(int count);
	//static void SubtractDateDemonstration(int count);
	//static void DateDiffDemonstration(int count);
	//static void ConsoleQueueInterface();
	//static void ConsoleDateInterface();
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
		DateTime temp;
		temp.randomFill();
		int priority = Utils::randInt(0, 10);
		q.push(temp, priority);
	}
	// popping
	DateTime temp;
	std::cout << "Popping " << count << " elements:\n";
	for (int i = 0; i < count; i++)
	{
		temp = q.pop();
	}
}