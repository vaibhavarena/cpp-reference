#include<iostream>

class Myclass
{
    private:
        int *_data;
        int _size;

    public:
        Myclass(size_t size)
        {
            _size = size;
            std::cout<<"Allocating memory at " << this << " of size " << _size * sizeof(int) << std::endl;
            _data = new int[_size];
        }

        ~Myclass()
        {
            std::cout<<"Deallocating memory at "<<this<<"\n";
            delete[] _data;
        }

        Myclass(const Myclass &source)
        {
            _size = source._size;
            _data = new int[_size];
            *_data = *source._data;
            std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
        }

        Myclass &operator=(const Myclass &source)
        {
            std::cout<<"Copy assignment operator\n";
            if(this == &source)
            return *this;
            _size = source._size;
            _data = new int[_size];
            *_data = *source._data;
            return *this;
        }

        Myclass(Myclass &&source)
        {
            std::cout<<"\nMove constructor : Copying data from "<< &source << " to "<< this << "\n";
            
            _size = source._size;
            _data = source._data;

            source._size = 0;
            source._data = nullptr;
        }

        Myclass &operator=(Myclass &&source)
        {
            std::cout<<"Move assignment operator\n";
            if(&source == this)
            return *this;

            delete[] _data;

            _data = source._data;
            _size = source._size;

            source._data = nullptr;
            source._size = 0;
            return *this;
        }
};

int main()
{
    Myclass m(10);
    
    m = Myclass(20);

    Myclass a = Myclass(30);
}