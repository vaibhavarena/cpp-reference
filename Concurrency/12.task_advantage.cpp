#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <cmath>
#include <vector>

void square(double x, int num)
{
    for(int i = 0;i<num;i++)
        std::sqrt(x);
}

int main()
{
    double y = 2345.1234;
    int nThreads = 10000;
    
    std::vector<std::future<void>> futures;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    // We get different time results while using async and deferred
    // For small tasks deferred can be used to speed up operations as there is overhead in creating task
    // and thus async in smaller computations will take more time
    // For large number of operations async will increase speed
    for(int i = 0;i<nThreads;i++)
    {
        futures.emplace_back(std::async(std::launch::async, square, y, nThreads));
    }

    for(const std::future<void> &x : futures)
        x.wait();

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    
    auto t = std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count();

    std::cout<<t << " milliseconds\n";
}