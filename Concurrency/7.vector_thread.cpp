#include <thread>
#include <iostream>
#include <vector>

void printHello()
{
    std::cout<<"Hello from worker thread "<< std::this_thread::get_id() << "\n";
}

int main()
{
    std::vector<std::thread> t;

    for(int i = 0;i<4;i++)
        t.emplace_back(std::thread(printHello));

    for(auto &x : t)    // Thread barrier
        x.join();
}