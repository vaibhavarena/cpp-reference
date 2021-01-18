// A friend class can access private members of other class
#include<iostream>
using std::cout;

class Heart{
    private:
        int rate{70};
        friend class Human;
};

class Human{
    private:
        Heart heart;
    public:
        void exercise(){
            heart.rate = 150;
        }

        int heartRate(){
            return (heart.rate);
        }
};

class Square{
    private:
        int side;
    public:
        Square(int s):side(s){cout<<"Side initialized - " << s << "\n";}
    
    friend class Rectangle;
};

class Rectangle{
    private:
        int width;
        int height;
    public:
        Rectangle(Square &a, Square &b) : width(a.side), height(b.side){
            cout<<"Area : "<<a.side * b.side << "\n";
        }
};

int main()
{
    Human human;
    cout<<human.heartRate() << "\n";
    human.exercise();
    cout<<human.heartRate() << "\n";
    Square a(4);
    Square b(5);
    Rectangle r(a, b);
}