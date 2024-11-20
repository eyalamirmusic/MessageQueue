#pragma once

#include "Queue.h"
#include <thread>

namespace EA::MessageQueue
{
inline void sleepThread(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

struct Thread
{
    Thread()
    {
        thread = std::thread([this] { run(); });
    }

    ~Thread()
    {
        shouldRun.store(false);

        while (running.load())
            sleepThread(1);

        thread.join();
    }

    void add(const Callback& cbToAdd) { queue.add(cbToAdd); }

private:
    void run()
    {
        running.store(true);

        while (shouldRun)
        {
            queue.run();
            sleepThread(1);
        }

        running.store(false);
    }

    Queue queue;
    std::atomic<bool> shouldRun {true};
    std::atomic<bool> running {false};
    std::thread thread;
};
} // namespace EA::MessageQueue
