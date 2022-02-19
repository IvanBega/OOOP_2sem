#include "UserInterface.h"

void UserInterface::Display()
{
	SelectQueue();
	std::cout << "Queue has been successfully selected!\n";
	Menu();
}

void UserInterface::SelectQueue()
{
	int option = 0;
	
	while (option < 1 || option > 4)
	{
		std::cout << "Choose data structure:\n1 - LinkedListQueue\n2 - VectorQueue\n3 - BSTQueue\n4 - BinaryHeapQueue\n";
		std::cin >> option;
	}
	
	// choosing data structure
	switch (option)
	{
	case 1:
		queue = new LinkedListQueue<DateTime>;
		break;
	case 2:
		queue = new VectorQueue<DateTime>;
		break;
	case 3:
		queue = new BSTQueue<DateTime>;
		break;
	case 4:
		queue = new BinaryHeapQueue<DateTime>;
		break;
	}
}

void UserInterface::Menu()
{
	int option = 0;
	while (option < 1 || option > 6)
	{
		std::cout << "1 - create current DateTime\n2 - print current DateTime\n3 - modify current DateTime\n4 - push current DateTime to queue\n5 - pop DateTime from queue to current\n6 - peek DateTime\n7 - exit";
		std::cin >> option;
	}
	switch (option)
	{
	case 1:
		CreateDateTime();
		break;
	}
}

void UserInterface::CreateDateTime()
{
	int option = 0;
	while (option < 1 || option > 3)
	{
		std::cout << "1 - fill DateTime from Console\n2 - fill DateTime randomly\n3 - menu";
		std::cin >> option;
	}
	switch (option)
	{
	case 1:
		FillDateTimeFromConsole();
		break;
	}
}

void UserInterface::FillDateTimeFromConsole()
{
	int year, month, day, hour, minute, second;
	while (true)
	{
		std::cout << "Enter Year, Month and Day: \n";
		std::cin >> year >> month >> day;
	}
}

UserInterface::UserInterface()
{
	Display();
}
