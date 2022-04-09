#pragma once
#include <iostream>
#include <chrono>
#include "DateTime.h"
#include "Time.h"
#include "Date.h"
#include "Utils.h"
#include "BinaryHeapQueue.h"
#include "BSTQueue.h"
#include "LinkedListQueue.h"
#include "VectorQueue.h"
/// <summary>
/// Class for console interaction with DateTime and priority queues
/// </summary>
class UserInterface
{
private:
	/// <summary>
	/// current DateTime
	/// </summary>
	DateTime* current = nullptr;
	/// <summary>
	/// priority queue
	/// </summary>
	Queue<DateTime*>* queue = nullptr;
	void Display();
	void SelectQueue();
	void StartMenu();
	void Menu();
	void CreateDateTime();
	void FillDateTimeFromConsole();
	void FillDateTimeRandom();
	void PrintCurrentDateTime();
	void ModifyCurrentDateTime();
	void AddTimeToDateTime();
	void AddDateToDateTime();
	void EnterTimePartFromConsole(int& hour, int& minute, int& second);
	void EnterDatePartFromConsole(int& year, int& month, int& day);
	void EnterDateFromConsole(int& year, int& month, int& day);
	void PushCurrentDateTime();
	void PeekDateTimeToCurrent();
	void PopDateTimeToCurrent();
public:
	UserInterface();
	~UserInterface();
};
