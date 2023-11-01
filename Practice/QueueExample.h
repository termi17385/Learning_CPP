#pragma once
#include <string>
#include "Queue.h"

struct Person
{
    std::string name;
    int age;
    double height;

    Person(const std::string& name, int age, double height)
        : name(name), age(age), height(height) { }
};

class QueueExample
{
public:
  
    /*

    Below is some examples of using the queue system,
    note that since we are using templates the queues can be
    a queue of almost anything.

    For example Queue<Person> which is a queue of the struct 'Person'
    you could also have a Queue of classes say you wanted to run tasks
    in the order of FIFO.

*/

    void integerQueue();
    void stringQueue();
    void personQueue();
    void testQueues();
};

