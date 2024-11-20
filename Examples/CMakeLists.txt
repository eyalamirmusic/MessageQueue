add_executable(Sync Sync.cpp)
target_link_libraries(Sync PRIVATE MessageQueue)

add_executable(Thread Thread.cpp)
target_link_libraries(Thread PRIVATE MessageQueue)

