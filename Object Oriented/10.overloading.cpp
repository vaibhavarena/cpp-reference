#include <iostream>

class Point{
    private:
        int i;
        int j;

    public:
        Point() : i(0), j(0) {};
        Point(int a, int b) : i(a), j(b) {};
        Point operator+(Point &adder){
            Point sum;
            sum.i = i + adder.i;
            sum.j = j + adder.j;
            return sum;
        }

        void show(){
            std::cout<< i << " " << j << "\n";
        }
};

int main()
{
    Point a(3,5);
    Point b(1,2);
    Point c = a + b;
    c.show();
}