// New and delete are operators while malloc and calloc are functions
// Memory leaks - When a memory is allocated in the heap but not properly deallocated
// Buffer overrun - When a memory outside the allocated memory is overwritten and thus corrupted, eg: str[5] but you strcpy("hello!") 
// '!' overwrites the next block of memory

#include<iostream>
#include<stdlib.h>

class myClass
{
    private:
        int *_number;
    public:

        myClass()
        {
            std::cout<<"Allocating memory\n";
            _number = (int*)malloc(sizeof(int));
        }

        ~myClass()
        {
            std::cout<<"\nDeallocating memory\n";
            free(_number);
        }

        void setNumber(int x)
        {
            *_number = x;
            std::cout<<"Number : "<<*_number;
        }        
};

int main()
{

    // Allocating memory for placement new. Placement new can be used when an object is allocated and de allocated memory
    // very frequently and can be used to optimize performance
    void* a = malloc(sizeof(myClass));

    // Placement new : new(block_of_memory)
    myClass* b = new(a) myClass;
    b->setNumber(23);
    delete b;
}