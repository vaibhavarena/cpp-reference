#include<iostream>
#include<thread>

void hello()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Hello, thread finished its execution\n";
}

int main()
{
    // Thread id
    std::cout<<"The id of current thread is : "<<std::this_thread::get_id() << "\n";

    // Number of threads in processor
    std::cout<<"The number of cpu cores in system : "<< std::thread::hardware_concurrency() << "\n";

    std::thread t(hello);
    // t.detach()   // Using it will variable joinable will be set to false, and the main program will not wait
                    // for execution of this thread. Threads once detached, cannot be ever joined again.
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout<<"Main program finished execution\n";
    t.join();   // Will wait for thread to finish execution, then execute following code
}