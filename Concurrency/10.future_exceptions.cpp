#include <iostream>
#include <thread>
#include <future>
#include <memory>
// Promises and futures can move information in one direction only
// They are meant for single time use only
void divideBy(std::promise<double> &&prms, double x, double y)
{
    try{
        if(y==0)
            throw std::runtime_error("This is a divide by zero error");
        else
            prms.set_value(x/y);
    }
    catch(...)
    {
        prms.set_exception(std::current_exception());
    }
}

int main()
{
    double num=49.0, denom=10.0;

    std::promise<double> prms;
    std::future<double> ftr = prms.get_future();

    std::thread t(divideBy, std::move(prms), num, denom);

    try{
        std::cout << ftr.get() << "\n";
    }
    catch(std::runtime_error e){
        std::cout<<e.what()<<"\n";
    }

    t.join();
}