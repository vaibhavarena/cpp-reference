#include <iostream>
#include <thread>
#include <future>
#include <memory>

class Vehicle
{
    private:
        int _id;
        std::unique_ptr<std::string> _name;

    public:
        Vehicle(): _id(0), _name(new std::string("Default name")){
            std::cout<<"Vehicle #" << _id << " Default constructor called\n";
        }

        Vehicle(int i, std::string s):_id(i), _name(new std::string(s)){
            std::cout<<"Vechile #"<<_id<< " Initializing constructor called\n";
        }

        Vehicle(Vehicle &&source):_name(std::move(source._name))
        {
            _id = source._id;
            source.setId(0);
            std::cout << "Vehicle #" << _id << " move constructor called" << std::endl;
        }

        int getId(){return _id;}
        std::string getName(){return *_name;}
        void setId(int i){_id = i;}
        void setName(std::string n){*_name = n;}
};

int main()
{
    Vehicle v;
    Vehicle v1(1, "Boost");

    std::future<void> ftr = std::async([](Vehicle v){
        v.setName("Vehicle 5");
    }, std::move(v));

    ftr.wait();
    
    // Will make programmer aware to avoid data race
    std::cout<<v.getName()<<"\n";   // It will throw error as it has been invalidated in move constructor
}