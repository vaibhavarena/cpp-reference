#include <iostream>
#include <future>
#include <thread>
#include <cmath>
#include <chrono>

void square(std::promise<double> &&prms, double x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    double y = sqrt(x);
    prms.set_value(y);
}

int main()
{
    double a = 100;

    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(square, std::move(prms), a);

    // The thread will return answer as soon as its ready or wait till timeout
    // It is guaranteed that the data will return
    auto status = ftr.wait_for(std::chrono::milliseconds(1000));

    if (status == std::future_status::ready)
    {
        auto x = ftr.get();
        std::cout<<x<<"\n";
    }

    else if(status == std::future_status::deferred || status == std::future_status::timeout)
    {
        std::cout<<"The thread has timed out or deferred\n";
    }

    t.join();
}