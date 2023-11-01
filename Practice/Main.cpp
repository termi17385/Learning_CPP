#include <iostream>
#include "Queue.h"

void integerQueue();
void stringQueue();

int main()
{
    std::cout << "------ Queue<int> ------" << std::endl;
    std::cout << std::endl;

    integerQueue();

    std::cout << std::endl;
    std::cout << "------ Queue<std::string> ------" << std::endl;
    std::cout << std::endl;

    stringQueue();
}

void integerQueue()
{
    Queue<int> myQueue;

    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.enQueue(4);
    myQueue.enQueue(5);

    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;

    while(!myQueue.isEmpty())  std::cout << "dequeuing: " << myQueue.deQueue() << std::endl;

    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;
}

void stringQueue()
{
    Queue<std::string> myQueue;
    
    myQueue.enQueue("Hello");
    myQueue.enQueue("World");
    myQueue.enQueue("How");
    myQueue.enQueue("Are");
    myQueue.enQueue("You?");

    std::cout << "Count: " << myQueue.size() << std::endl;
    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;

    while (myQueue.size() > 1) std::cout << "dequeuing: " << myQueue.deQueue() << std::endl;
    
    std::cout << "Count: " << myQueue.size() << std::endl;
    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;

}