#include <iostream>
#include <memory>
#include <thread>
#include <future>
#include <mutex>
#include <vector>
#include <chrono>
#include <algorithm>

class Vehicle
{
    public:
        Vehicle(int i):_id(i){}
        int getId(){return _id;}
    private:
        int _id;
};

class WaitingVehicle{
    private:
        std::vector<Vehicle> _vehicles;
        std::timed_mutex _mutex;

    public:
        WaitingVehicle(){}

        void pushBack(Vehicle &&v)
        {
            for(int i =0 ;i<3;i++)          // Try acquiring lock 3 times
            {
                if(_mutex.try_lock_for(std::chrono::milliseconds(1000)))
                {
                    _vehicles.emplace_back(std::move(v));

                    // Introducing explicit wait below to expose data races
                    std::this_thread::sleep_for(std::chrono::microseconds(1000));   

                    _mutex.unlock();
                    break;
                }
                else
                {
                    std::cout<<"Vehicle# "<< v.getId() << " could not be place in the queue\n";
                    std::this_thread::sleep_for(std::chrono::milliseconds(100));
                }
            }            
        }

        void printSize()
        {
            _mutex.lock();
            std::cout<<"Size of vehicles queue "<<_vehicles.size()<<"\n";
        }
};

int main()
{
    std::shared_ptr<WaitingVehicle> queue(new WaitingVehicle);
    std::vector<std::future<void>> futures;

    for(int i = 0;i<1000;i++)
    {
        Vehicle v(i);
        futures.emplace_back(std::async(std::launch::async, &WaitingVehicle::pushBack, queue, std::move(v)));
    }

    std::for_each(futures.begin(), futures.end(), [](std::future<void> &ftr){
        ftr.wait();
        });

    queue->printSize();
}