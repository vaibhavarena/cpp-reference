#include<iostream>
#include<cassert>
using std::cout;

struct Date{
private:
    int day{1};
    int month{1};
    int year{1};

public:
    int Day(){return day;}      // Accessors
    void Day(int d){            // Mutators
        if(day > 0 && day <= 31)             // Invariants (or logic)
            day = d;
        }                       
    int Month(){return month;}
    void Month(int m){
        if(month > 0 && month <= 12)
            month = m;
        }
    int Year(){return year;}
    void Year(int y) {year =y;}
};

int main()
{
    Date date;

    date.Day(10);
    date.Month(11);
    date.Year(2000);

    assert(date.Day() <= 30);
    assert(date.Month() <= 12);
    assert(date.Year() == 2000);

    cout<<"Date : "<<date.Day() <<", Month : "<<date.Month() << ", Year : "<<date.Year() << "\n";

    return 0;
}