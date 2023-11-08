#include "Todo.h"

#include<fstream>

TodoData::TodoData(std::string _todoDescription, bool status = false)
{
	todoDescription = _todoDescription;
	completed = status;
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

		// I hate cin :(

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

		else if (ans == "E" || ans == "e" || todoList.size() <= 0) running = false;

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
	TodoData* ptr = &todoList[_position]; // pointer so we can actually modify the object
	std::cout << "Edit Description (ED), Change Completetion Status (CS) or Exit (E): ";
		
	std::string ans;
	std::getline(std::cin, ans);

	if (ans == "ED" || ans == "ed") ptr->todoDescription = getEntryDescription();
	else if (ans == "CS" || ans == "cs") ptr->completed = !ptr->completed;
	
	todoList[_position] = *ptr; // make sure the object is actually modified (probably redundant)
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
	std::string line;
	std::ifstream file(FILE_NAME);
	std::cout << std::endl;
	
	char delim = ',';

	// while words exist in the file
	while (std::getline(file, line))
	{
		// get the position of the delim
		int position = line.find(delim);
		std::string desc = line.substr(0, position); // get the text, before the delim, we know it is a description
		line.erase(0, position + 1); // erase the text and delim
		bool status = std::stoi(line); // convert the last piece of text back to boolean

		// add new entry to list
		TodoData t(desc, status);
		todoList.push_back(t);
	}

	file.close();
}

Todo::~Todo()
{
	// Destructor, called at the end of the life
	// of this object

	// being used to save data at the end
	saveEntries();
}