#include <iostream>
#include <thread>
#include <memory>

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void printID()
    {
        std::cout << "Vehicle ID = " << _id << std::endl;
    }
    void setName(std::string n){
        _name = n;
    }
    void printName(){
        std::cout<<"Name : " << _name << "\n";
    }

private:
    int _id;
    std::string _name;
};

int main()
{
    // create thread
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t1 = std::thread(&Vehicle::addID, v, 121); // call member function on object v
    std::thread t2 = std::thread(&Vehicle::setName, v, "Forza"); // call member function on object v

    // wait for thread to finish
    t1.join();
    t2.join();

    // print Vehicle id
    v->printID();
    v->printName();

    return 0;
}