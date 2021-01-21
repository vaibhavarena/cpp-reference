#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void printName(std::string &n)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    n += " (from thread)";
    std::cout << n <<"\n";
}

int main()
{
    std::string name = "MyThread";
    std::thread t(printName, std::ref(name));

    t.join();


    name += " (from Main)";
    std::cout<<name <<"\n";
}