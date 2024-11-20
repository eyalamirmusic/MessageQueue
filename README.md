# MessageQueue

A simple C++ header only message queue

You can use either a sync queue that you run on your own thread (for example, using the OS
event loop or a timer) or you can use the included threaded version to spawn a dedicated thread.

Messages are safe to pass from any thread, icluding from the callback

Example uses are:
```c++
//If you already have a thread or message loop:
EA::MessageQueue::Queue queue;

auto func = [] { std::cout << "Running!\n"; };

queue.add(func);
queue.add(func);
queue.add(func);

//All calls would only happen here
queue.run();
```

```c++
auto func = [] { std::cout << "Running on side thread!\n"; };

EA::MessageQueue::Thread thread;

thread.add(func);
thread.add(func);
thread.add(func);

//Calls would happen on the side thread
EA::MessageQueue::sleepThread(3000);
```