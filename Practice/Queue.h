#pragma once

#include<iostream>
#include <sstream>

template<typename T>
struct Node
{
	T data;
	Node<T>* next;

	Node(T _value) : data(_value), next(nullptr) {}
};

template<typename T>
class Queue
{
	Node<T>* head;
	size_t count = 0;

public:
	Queue() : head(nullptr) {}

	void enQueue(T _obj);
	T deQueue();
	T& peek();

	bool isEmpty();
	size_t size() { return count; }

	std::string displayContents();
};

template<typename T>
inline void Queue<T>::enQueue(T _element)
{
	Node<T>* newNode = new Node<T>(_element);
	if (!head) head = newNode;
	else
	{
		Node<T>* current = head;
		while (current->next)
		{
			current = current->next;
		}
		current->next = newNode;
	}

	count++;
}

template<typename T>
inline T Queue<T>::deQueue()
{
	if (isEmpty()) throw std::runtime_error("Queue is empty. Cannot dequeue.");

	T value = head->data;
	
	Node<T>* oldHead = head;

	head = head->next;

	delete oldHead;

	count--;

	return value;
}

template<typename T>
inline T& Queue<T>::peek() { return head->data; }

template<typename T>
inline bool Queue<T>::isEmpty() { return !head; }

template<typename T>
inline std::string Queue<T>::displayContents()
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
