#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
#include <mutex>
#include <vector>
#include <chrono>

std::mutex _mutex;
double result;

void printResult()
{
    std::cout<<"Result : "<< result << "\n";
}

void divideByZero(double num, double denom)
{

    try{
        if(denom!=0)
        {
            // Lock is released when the lock_guard variable goes out of scope
            // So no need to take special care to unlock when exception occurs
            std::lock_guard<std::mutex> lck(_mutex);
            // Use unique_lock to lock and unlock at specific line to acquire the resource for less time
            // std::unique_lock<std::mutex> lck(_mutex);

            result = num/denom;
            std::this_thread::sleep_for(std::chrono::microseconds(100));
            printResult();
        }
        
        else
        {
            throw std::invalid_argument("The denominator is equal to zero");
        }
    }


    catch(const std::invalid_argument &e)
    {
        std::cout<<"The error is " << e.what() << "\n";
    }
}


int main()
{
    std::vector<std::future<void>> ftr;

    for(int i = -5;i<5;i++)
    {
        ftr.emplace_back(std::async(std::launch::async, divideByZero, 10, i));
    }

    std::for_each(ftr.begin(), ftr.end(), [](std::future<void> &f){
        f.wait();
    });
}