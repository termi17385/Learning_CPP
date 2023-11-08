#include "Todo.h"

#include<fstream>

TodoData::TodoData(std::string _todoDescription)
{
	todoDescription = _todoDescription;
}

void Todo::run()
{
	char running = true;

	std::string ans = "";

	if (todoList.size() <= 0)
	{
		std::cout << "Creating new entry as non exist currently...." << std::endl;

		createEntry();
	}	
	
	do
	{
		display();

		std::cout << "Create Entry (CE), Edit Entry (EE), Remove Entry (RE), Exit (E): ";

		std::cin >> ans;
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		std::cout << std::endl;

		if (ans == "CE" || ans == "ce") createEntry();
		if (ans == "EE" || ans == "ee")
		{ 
			size_t position;
			
			std::cout << "Which Entry do you want to edit? (num): ";

			std::cin >> position;

			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear out the input buffer.
			
			editEntry(position); 

			std::cout << std::endl;
		}
		if (ans == "RE" || ans == "re")
		{
			size_t position;
			
			std::cout << "Which Entry do you want to remove? (num): ";
			
			std::cin >> position;
			
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear out the input buffer.

			removeEntry(position);
			
			std::cout << std::endl;
		}

		else if (ans == "E" || ans == "e") running = false;

	} while (running);
}

void Todo::display()
{
	for (size_t i = 0; i < todoList.size(); i++)
	{
		auto& entry = todoList[i];
		std::string desc = entry.todoDescription;
		bool status = entry.completed;

		std::string completed = "[x]";
		std::string notCompleted = "[]";

		std::cout << i << ". " << (status ? completed : notCompleted) << " " << desc << std::endl;
	}

	std::cout << std::endl;;
}

void Todo::createEntry()
{
	std::cout << "New entry being created..." << std::endl << std::endl;
	std::string description = getEntryDescription();
	TodoData data = TodoData(description);
	todoList.push_back(data);
}

std::string Todo::getEntryDescription()
{
	std::string sentence;
	
	std::cout << "Enter task description: " << std::endl;
	
	std::getline(std::cin, sentence);
	
	return sentence;
}

void Todo::removeEntry(size_t _position)
{
	todoList.erase(todoList.begin() + _position);
}

void Todo::editEntry(size_t _position)
{
	std::string ans;
	
	TodoData* ptr = &todoList[_position];
	
	std::cout << "Edit Description (ED), Change Completetion Status (CS) or Exit (E): ";
	
	std::getline(std::cin, ans);

	if (ans == "ED" || ans == "ed") ptr->todoDescription = getEntryDescription();
	
	else if (ans == "CS" || ans == "cs") ptr->completed = !ptr->completed;
	
	todoList[_position] = *ptr;
}


void Todo::saveEntries()
{
	std::string text;
	std::ofstream outFile(FILE_NAME);

	for (size_t i = 0; i < todoList.size(); i++)
	{
		TodoData& t = todoList[i];

		std::string desc = t.todoDescription;
		std::string status = std::to_string(t.completed); // saves as int apparently

		text += (desc + "," + status + "\n");
	}

	if (outFile.is_open())
	{
		outFile << text;
		outFile.close();
	}
}	

void Todo::readEntries()
{
	
}

Todo::~Todo()
{
	saveEntries();
}