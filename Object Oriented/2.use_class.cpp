#include <iostream>
#include <cassert>
using std::cout;

class Date{
private:
    int day{1};
    int month{1};
    int year{0};
    int DaysInMonth(int month, int year) const;
    bool LeapYear(int year) const;

public:
    Date(int d, int m, int y);
    
    int Day() const{return day;}
    int Month() const{return month;}
    int Year() const{return year;}
    
    void Day(int d){
    if(day >0 && day <=31)
        day = d;
    }
    void Month(int m){
    if(month > 0 && month <=12)
        month = m;
    }
    void Year(int y){year = y;}

    void printDate()
    {
        cout<<"Day : "<< Day() <<", Month : "<< Month() << ", Year : "<< Year() << "\n";
    }
};

Date::Date(int d, int m, int y): year(y){   // Initializer list     - Can be used to initialize constants
    Day(d); 
    Month(m);
}

int Date::DaysInMonth(int month, int year) const{
    if(month == 2)
        return LeapYear(year) ? 29 : 28;
    else if (month == 4  || month == 6 || month == 9 || month == 11)
        return 30;
    else 
        return 31;

}

bool Date::LeapYear(int year) const{
    if(year%4!=0)
        return false;
    else if(year%100!=0)
        return true;
    else if(year%400!=0)
        return false;
    else
        return true;
}


// Test in main
int main()
{
    Date date(28,2, 2001);
    assert(date.Day() != -1);
    assert(date.Month() != 14);
    assert(date.Year() == 2001);
    date.printDate();
}
