#pragma once

#include <vector>
#include <functional>

namespace EA::MessageQueue
{
using Callback = std::function<void()>;

struct Queue
{
    using Callbacks = std::vector<Callback>;

    void add(const Callback& cbToAdd)
    {
        std::lock_guard lock(mutex);
        callbacks.emplace_back(cbToAdd);
    }

    void run()
    {
        /*We can't directly use callbacks, because 'add()' might be called
         *as a result of a callback.
         *So we need a 'safe' copy of the callbacks that won't be modified.
         */
        auto safeCallbacks = getSafeCallbacks();

        for (auto& cb: safeCallbacks)
            cb();
    }

private:
    Callbacks getSafeCallbacks()
    {
        std::lock_guard lock(mutex);
        auto safe = callbacks;
        callbacks.clear();
        return safe;
    }

    std::recursive_mutex mutex;
    Callbacks callbacks;
};

} // namespace EA::MessageQueue