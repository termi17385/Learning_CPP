#pragma once
#include <iostream>
#include <string>
#include <vector>

const std::string FILE_NAME = "List.td";

struct TodoData
{
	std::string todoDescription = "";
	bool completed = false;

	TodoData(std::string);
};

class Todo
{
public:
	Todo() 
	{
		std::cout << "------------TODO LIST------------" << std::endl << std::endl;

		readEntries();
	};
	
	void run();

	~Todo();
private:
	
	void display();

	std::vector<TodoData> todoList;

	TodoData* getEntry(size_t _index) { return &todoList[_index]; }
	std::string getEntryDescription();	// description of TodoData Entry (the task)

	void createEntry();	
	void removeEntry(size_t _position);
	void editEntry(size_t _position);

	void saveEntries();
	void readEntries();
};

