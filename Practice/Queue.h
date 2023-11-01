#pragma once

#include<iostream>
#include <sstream>

/*
||-------------------------------------------------
|| Linked List Example
||
|| This is a variant of a linked list, 
|| used to create a First in First out queue (FIFO)
||
|| When dealing with a linked list, remember that each node 
|| has a its data, and the address of the next node, this is a 
|| singly linked list, while a doubly linked list has an address to
|| the previous node, address to the next node, and its data.
||
||
|| A queue can be though of like a line at a shopping center
||---------------------------------------------------

	< not entirely sure how inline works yet, but I know it is required >
	< when dealing with templates.										>

	Useful resources:
	* template<typename T> + massive playlist for C++: https://www.youtube.com/watch?v=spZd2rNtze8&list=PLZPZq0r_RZOMHoXIcxze_lP97j2Ase2on&index=52
	* LinkedList: https://www.youtube.com/watch?v=N6dOwBde7-M
	* Queues: https://www.youtube.com/watch?v=nqXaPZi99JI
*/


template<typename T>
struct Node
{
	T data;			// Stored data / information of the node
	Node<T>* next;	// The address of the next node
	Node(T _value) : data(_value), next(nullptr) {}
};

template<typename T>
class Queue
{
	Node<T>* head;		// the start of the queue
	Node<T>* tail;		// the end of the queue
	size_t count = 0;	// size

public:
	Queue() : head(nullptr), tail(nullptr) {}	// initialise nodes
	
	void enQueue(T);			// stores to the end of the queue (end queue)
	T deQueue();				// removes and returns the data of the first element of the queue (FIFO)
	
	T& peek();					// peeks the top element
	T& peekTail();				// same as the standard peek but shows the tail
	
	size_t size() { return count; }
	bool isEmpty();				// validates if the queue is empty

	void clear();

	std::string displayContents();

	~Queue() // destructor to clean up memory after the life time of the object
	{
		Node<T>* current = head;
		while (current)
		{
			Node<T>* next = current->next;
			delete current;
			current = next;
		}
	}
};

/// <summary>
/// <br>Enqueuing means to add element to the end of the queue,</br>
/// <br>we do this in order to follow the First in First out (FIFO) principle</br>
/// </summary>
/// <param name="_element">The element we want to add to the queue</param>
template<typename T> inline void Queue<T>::enQueue(T _element)
{
	// creates a new node setting the data to _element
	Node<T>* newNode = new Node<T>(_element);
	
	// Make sure the queue has a head first
	if (!head)
	{
		// sets up the head and tail
		head = newNode;
		tail = head;
	}
	else
	{
		Node<T>* prev_tail = tail;	// We set the tail to a temp prev_tail variable
		tail = newNode;				// then set the tail to the new node
		prev_tail->next = tail;		// and link the previous tail to the new tail
	}

	count++;
}

/// <summary>
/// <br>Dequeue (remove) element from the queue </br>
/// <br>Used to get the first element in the queue and always will due to the First in First out principle</br>
/// </summary>
template<typename T> inline T Queue<T>::deQueue()
{
	// Throws an exception if we try to dequeue on an empty queue, probably should just return null
	if (isEmpty()) throw std::runtime_error("Queue is empty. Cannot dequeue.");

	// stores the value in the head pointer
	T value = head->data;
	
	// stores the value of the old head for deletion
	Node<T>* oldHead = head;

	// sets the head to the next node
	head = head->next;

	// deletes the old head pointer to free up memory
	delete oldHead;

	count--;

	return value;
}

/// <summary>
/// Only gives a reference to the head of the queue, can be used to ensure no issues with dequeuing
/// </summary>
template<typename T> inline T& Queue<T>::peek() { return head->data; }

template<typename T> inline T& Queue<T>::peekTail() { return tail->data; }

template<typename T> inline bool Queue<T>::isEmpty() { return !head; }

template<typename T> inline void Queue<T>::clear()
{
	Node<T>* current = head;
	while (current)
	{
		Node<T>* next = current->next;
		delete current;
		current = next;
	}

	head = nullptr;
	tail = nullptr;
	count = 0;
}

/// <summary>
/// will just display the whole queue to console
/// </summary>
/// <typeparam name="T"></typeparam>
/// <returns></returns>
template<typename T> inline std::string Queue<T>::displayContents()
{
	std::ostringstream oss{};
	Node<T>* current = head;
	oss << "[";
	while (current)
	{
		T value = current->data;
		oss << value;
		current = current->next;
		if (current) oss << ",";
	}
	oss << "]";

	return oss.str();
}
