#pragma once
#include <iostream>
#include <string>
#include <vector>

const std::string FILE_NAME = "List.td";

/*
||-------------------------------------------------
|| Todo List Project
||
|| This program is mostly for reminding how the file streams work,
|| and delims, substr, find and erase.
||
|| Basic use of pointers and file stream
||
||---------------------------------------------------*/



struct TodoData
{
	std::string todoDescription = "";
	bool completed = false;

	TodoData(std::string, bool status);
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

	std::string getEntryDescription();	// description of TodoData Entry (the task)

	void createEntry();	
	void removeEntry(size_t _position);
	void editEntry(size_t _position);

	void saveEntries();
	void readEntries();
};

