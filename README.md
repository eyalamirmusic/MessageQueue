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

To build the examples, you can use this on Mac:
```
cmake -G Xcode -B build -D BUILD_EXAMPLES=1
```
Or on Windows:
```
cmake -G "Visual Studio 17 2022" -B build -D BUILD_EXAMPLES=1
```

When linking directly against it in CMake, you can just link against this interface lib:
```cmake
target_link_libraries(MyApp PRIVATE MessageQueue)
```

And then include either:
```c++
#include <MessageQueue/Queue.h>
```
Or:
```c++
#include <MessageQueue/Thread.h>
```