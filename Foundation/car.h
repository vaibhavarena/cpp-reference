#ifndef CAR_H
#define CAR_H
#include<iostream>
#include <string>
using std::string;
using std::cout;

class Car {
  public:
    void PrintCarData();
    void IncrementDistance();
    
    Car(string c, int n) : color(c), number(n) {}

  private:
    string color;
    int distance = 0;
    int number;
};

#endif