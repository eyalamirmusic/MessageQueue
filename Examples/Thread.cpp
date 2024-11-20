#include <MessageQueue/Thread.h>
#include <iostream>

int main()
{
    namespace Queue = EA::MessageQueue;

    auto func = [] { std::cout << "Running on side thread!\n"; };

    Queue::Thread thread;

    for (int index = 0; index < 5; ++index)
    {
        Queue::sleepThread(1000);
        thread.add(func);
    }

    Queue::sleepThread(3000);
    return 0;
}