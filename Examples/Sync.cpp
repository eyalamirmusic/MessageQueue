#include <MessageQueue/Queue.h>
#include <iostream>

int main()
{
    EA::MessageQueue::Queue queue;

    auto func = [] { std::cout << "Running!\n"; };

    queue.add(func);
    queue.add(func);
    queue.add(func);

    queue.run();
    return 0;
}