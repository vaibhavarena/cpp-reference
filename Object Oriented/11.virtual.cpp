#include<iostream>

class Shapes{
    public:
    virtual void Area() const = 0;  // = 0 is the definition of a pure virtual function
    virtual void Perimeter() const = 0;     // A pure virtual function must be defined in derived class,
};                                           // or derived class will also become abstract class

class Square : public Shapes{
    private:
        int side;
    public:

        Square() : side(4){};
        void Area() const{
            std::cout <<  side * side << "\n";
        }

        void Perimeter() const{
            std::cout<< side * 4 << "\n";
        }
};

class Rectangle: public Shapes{
    private:
        int length;
        int breadth;
    
    public:

        Rectangle() : length(5), breadth(4) {}
        void Area() const{
            std::cout<< length * breadth << "\n";
        }

        void Perimeter() const{
            std::cout<< length * 2 + breadth * 2 << "\n";
        }
};

// Overriding
class Parallelogram : public Rectangle{
    private:
        float base;
        float height;

    public:
        Parallelogram() : base(5), height(4) {}

        void Area() const{
            std::cout << 0.5 * base * height;
        }
};

int main()
{
    Square square;
    Rectangle rec;
    Parallelogram par;
    square.Area();
    square.Perimeter();
    rec.Area();
    rec.Perimeter();
    par.Area();     // Overridden function
    par.Perimeter();// Non overridden function
}