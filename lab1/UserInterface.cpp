#include "UserInterface.h"

UserInterface::~UserInterface()
{
	delete queue;
	delete current;
}

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
		queue = new LinkedListQueue<DateTime*>;
		break;
	case 2:
		queue = new VectorQueue<DateTime*>;
		break;
	case 3:
		queue = new BSTQueue<DateTime*>;
		break;
	case 4:
		queue = new BinaryHeapQueue<DateTime*>;
		break;
	case 5:
		break;
	}
}

void UserInterface::Menu()
{
	bool flag = true;
	while (flag)
	{
		int option = 0;
		while (option < 1 || option > 7)
		{
			std::cout << "\n--------------------------------------------------\n1 - create current DateTime\n2 - print current DateTime\n3 - modify current DateTime\n4 - push current DateTime to queue\n5 - pop DateTime from queue to current\n6 - peek DateTime\n7 - exit\n--------------------------------------------------\n\n";
			std::cin >> option;
		}
		switch (option)
		{
		case 1:
			CreateDateTime();
			break;
		case 2:
			PrintCurrentDateTime();
			break;
		case 3:
			ModifyCurrentDateTime();
			break;
		case 4:
			PushCurrentDateTime();
			break;
		case 5:
			PopDateTimeToCurrent();
			break;
		case 6:
			PeekDateTimeToCurrent();
			break;
		case 7:
			flag = false;
			break;
		}
	}
}

void UserInterface::CreateDateTime()
{
	int option = 0;
	while (option < 1 || option > 3)
	{
		std::cout << "1 - fill DateTime from Console\n2 - fill DateTime randomly\n3 - menu\n";
		std::cin >> option;
	}
	switch (option)
	{
	case 1:
		FillDateTimeFromConsole();
		break;
	case 2:
		FillDateTimeRandom();
		break;
	case 3:
		break;
	}
}

void UserInterface::FillDateTimeFromConsole()
{
	int year, month, day, hour, minute, second;
	//delete current;
	EnterDatePartFromConsole(year, month, day);
	EnterTimePartFromConsole(hour, minute, second);
	

	current = new DateTime(year, month, day, hour, minute, second);
	std::cout << "You've entered: " << *current << "\n";
}

void UserInterface::FillDateTimeRandom()
{
	current = new DateTime();
	current->randomFill();
	std::cout << "You have randomly filled DateTime: " << *current << "\n";
}

void UserInterface::PrintCurrentDateTime()
{
	if (current != nullptr)
	{
		std::cout << "Current DateTime is: " << *current << "\n";
	}
	else
		std::cout << "Current DateTime is empty!\n";
}

void UserInterface::ModifyCurrentDateTime()
{
	int option = 0;
	while (option < 1 || option > 3)
	{
		std::cout << "1 - add time\n2 - add date\n3 - menu\n";
		std::cin >> option;
		switch (option)
		{
		case 1:
			AddTimeToDateTime();
			break;
		case 2:
			AddDateToDateTime();
			break;
		case 3:
			break;
		}
	}
}

void UserInterface::AddTimeToDateTime()
{
	int hour, minute, second;
	EnterTimePartFromConsole(hour, minute, second);
	current->addTime(hour, minute, second);
}

void UserInterface::AddDateToDateTime()
{
	int year, month, day;
	EnterDateFromConsole(year, month, day);
	current->addDate(year, month, day);
}

void UserInterface::EnterTimePartFromConsole(int& hour, int& minute, int& second)
{
	while (true)
	{
		std::cout << "Enter, Hour, Minute and Second:\n";
		std::cin >> hour >> minute >> second;
		if (!DateTime::isTimeCorrect(hour, minute, second))
		{
			std::cout << "Time is incorrect! Please enter again:\n";
		}
		else
		{
			break;
		}
	}
}

void UserInterface::EnterDatePartFromConsole(int& year, int& month, int& day)
{
	while (true)
	{
		std::cout << "Enter Year, Month and Day: \n";
		std::cin >> year >> month >> day;
		if (!DateTime::isDateCorrect(year, month, day))
		{
			std::cout << "Date is incorrect! Please enter again:\n";
		}
		else
		{
			break;
		}
	}
}

void UserInterface::EnterDateFromConsole(int& year, int& month, int& day)
{
	while (true)
	{
		std::cout << "Enter Year, Month and Day: \n";
		std::cin >> year >> month >> day;
		if (!Date::isCorrect(year, month, day))
		{
			std::cout << "Date is incorrect! Please enter again:\n";
		}
		else
		{
			break;
		}
	}
}

void UserInterface::PushCurrentDateTime()
{
	int priority = 0;
	std::cout << "Enter priority for current DateTime: \n";
	std::cin >> priority;
	queue->push(current, priority);
	std::cout << "Pushed " << *current << " to the queue under priority << " << priority << "\n";
}

void UserInterface::PeekDateTimeToCurrent()
{
	if (queue->empty())
	{
		std::cout << "Unable to pop, queue is empty\n";
		return;
	}
	current = queue->peek();
	std::cout << "Peeked DateTime to current: " << *current << "\n";
}

void UserInterface::PopDateTimeToCurrent()
{
	if (queue->empty())
	{
		std::cout << "Unable to pop, queue is empty\n";
		return;
	}
	current = queue->pop();
	std::cout << "Popped DateTime to current: " << *current << "\n";
}

UserInterface::UserInterface()
{
	Display();
}
