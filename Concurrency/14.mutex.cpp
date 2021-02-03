#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <future>
#include <memory>
#include <algorithm>

class Vehicle
{
    private:
        int _id;
    public:
        Vehicle(int i) : _id(i) {}
};

class WaitingClass
{
    private:
        std::vector<Vehicle> _vehicle;
        std::mutex _mutex;

    public:

        WaitingClass(){}

        void printSize()
        {
            _mutex.lock();
            std::cout<<"Vehicle# "<<_vehicle.size()<<"\n";
            _mutex.unlock();
        }

        void pushBack(Vehicle &&v)
        {
            _mutex.lock();
            _vehicle.emplace_back(std::move(v));
            _mutex.unlock();
        }
};

int main()
{
    std::shared_ptr<WaitingClass> queue(new WaitingClass);
    std::vector<std::future<void>> futures;

    for(int i = 0;i<1000;i++)
    {
        Vehicle v(i+1);
        futures.emplace_back(std::async(std::launch::async, &WaitingClass::pushBack, queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr){
        ftr.wait();
    });

    queue->printSize();
}