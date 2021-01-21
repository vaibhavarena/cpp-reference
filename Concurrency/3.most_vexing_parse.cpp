// Use argument -pthread in g++ to use multi threading

#include<iostream>
#include<thread>

class Vehicle
{
    private:
        int _id;

    public:

        Vehicle(int i):_id(i){};

        void operator()()
        {
            std::cout<<"Vehicle #"<< _id << " is now active\n";
        }
};

int main()
{
    // std::thread t0(Vehicle());   Will give error as Vehicle is interpreted as a function, not an anonymous object

    // Methods to overcome above errors
    // Use extra parenthesis
    std::thread t1((Vehicle(1)));

    // Use copy initialization
    std::thread t2 = std::thread(Vehicle(2));

    // Use uniform initialization with braces
    std::thread t3{Vehicle(3)};

    std::cout<<"Finished working in main\n";

    t1.join();
    t2.join();
    t3.join();

}