#include<iostream>
// Principles are to abstract the object creation and deletion so programmer has to be least worried about 
// allocation and deallocation of the object
class myDouble
{
    private:
        double *_p;
    public:
        myDouble(double *p)
        {
            _p = p;
        }

        ~myDouble()
        {
            delete _p;
        }

        double &operator*()
        {
            return *_p;
        }
};

int main()
{
    double den[] = {1.0, 2.0, 3.0, 4.0};

    for(int i = 0;i<4;i++)
    {
        myDouble x(new double(i));     // Returns a pointer of type double

        std::cout<<*x << " " <<  *x/den[i] << "\n";
        
        // Object deallocation is automatically taken care by the destructor
    }
}