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
class UserInterface
{
private:
	DateTime* current = nullptr;
	Queue<DateTime>* queue = nullptr;
	void Display();
	void SelectQueue();
	void Menu();
	void CreateDateTime();
	void FillDateTimeFromConsole();
public:
	UserInterface();
};
