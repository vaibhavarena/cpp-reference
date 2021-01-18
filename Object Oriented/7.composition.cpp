#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#define pi 3.14159
using std::string;
using std::cout;
using std::vector;

// Usage 1
class Wheels{
    public:
        float diameter;
        Wheels() : diameter(50){};
};

class Car{
    public:
        vector<Wheels> wheels;
        Car():wheels(4, Wheels()){}
};

// Usage 2
class LineSegment{
    public:
        int length;
    
    LineSegment(int l) : length(l){};
};

class Circle{
    private:
        LineSegment &radius;

    public:
        Circle(LineSegment &radius_) : radius(radius_){};

        double Area(){
            return pi * std::pow(radius.length, 2);
        }
};

int main()
{
    Car car;
    LineSegment radius{5};
    Circle circle(radius);
    cout << car.wheels.size() << "\n";
    cout<< "Area of circle : " << circle.Area() << "\n";
}