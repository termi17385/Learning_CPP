#include "QueueExample.h"
#include <iostream>

void QueueExample::integerQueue()
{
    // Demonstrates a queue of integers, tests mass enqueuing, mass dequing clearing and adding back

    Queue<int> myQueue;

    // "adding to the queue
    // remember this is adding to the tail(end) of the queue

    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.enQueue(4);
    myQueue.enQueue(5);

    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;

    while (!myQueue.isEmpty())  std::cout << "dequeuing: " << myQueue.deQueue() << std::endl;

    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;

    myQueue.enQueue(5);
    int data = 0;

    Node<int> node = myQueue.peek();
    while (myQueue.size() < 5)
    {
        data += node.data * node.data;
        myQueue.enQueue(data);
        std::cout << "enqueuing: " << data << std::endl;
    }

    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;
    std::cout << "Clearing queue...." << std::endl;
    myQueue.clear();
    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;
    myQueue.enQueue(2);
    std::cout << "MyQueue: " << myQueue.displayContents() << std::endl;
}

void QueueExample::stringQueue()
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

void QueueExample::personQueue()
{
    Queue<Person> myQueue{};

    // Simple use case, with a queue of people

    myQueue.enQueue(Person("Alice", 25, 160.5));
    myQueue.enQueue(Person("Eve", 35, 163.9));
    myQueue.enQueue(Person("Jack", 99, 200.0));

    /*
    *   Thanks GPT
    *
        In C++, when you create a variable, you typically need to specify its data type,
        like int, double, or std::string,
        when you declare it. However, sometimes the data type can be complex or lengthy,
        especially when working with things like iterators or complex data structures.

        auto simplifies this by saying,
        "You know what, computer? You figure out the data type for me!"
        It's like having the computer do the heavy lifting of data type determination.
        When you use auto, C++ looks at the expression on the right side of the assignment
        and decides what data type the variable should be based on that.
    */

    // Auto allows you to tell the computer, figure out the type for me really useful if you cannot remember the
    // type or the type is too long to write.

    // Its best practice to avoid using auto, from what I know
    // see above for GPT detailed response :)

    // Peeking the top allows us to get the 
    // next element without actually de queuing it
    // useful for checking information 
    std::cout << "Starting Queue Size: " << myQueue.size() << std::endl << std::endl;

    while (!myQueue.isEmpty())
    {

        Person nextInQueue = myQueue.peek();

        auto& name = nextInQueue.name;
        auto age = nextInQueue.age;
        auto height = nextInQueue.height;

        std::cout << "Person: " << name << " age: " << age << " height " << height << std::endl;
        std::cout << "Queue Size: " << myQueue.size() << std::endl;

        std::cout << "DeQueuing: " << myQueue.deQueue().name << std::endl << std::endl;
    }
}

void QueueExample::testQueues()
{
	std::cout << "------ Queue<int> ------" << std::endl;
	std::cout << std::endl;

	integerQueue();

	std::cout << std::endl;
	std::cout << "------ Queue<std::string> ------" << std::endl;
	std::cout << std::endl;

	stringQueue();

	std::cout << std::endl;
	std::cout << "------ Queue<Person> ------" << std::endl;
	std::cout << std::endl;

	personQueue();
}
