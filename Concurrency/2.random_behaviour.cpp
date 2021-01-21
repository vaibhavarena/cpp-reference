// Use argument -pthread in g++ to use multi threading

#include<iostream>
#include<thread>

// Tasks 1 and 2 from main and thread will be randomly executed first as the process execution
// depends on the OS scheduler and any thread can be given the priority

void threadFunction()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"Thread Task 1 : Finished\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"Thread Task 2 : Finished\n";
}

int main()
{
    std::thread t(threadFunction);

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"Main Task 1 : Finished\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"Main Task 2 : Finished\n";

    t.join();       // Will wait for thread to finish execution, then execute following code
}