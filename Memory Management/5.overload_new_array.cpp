// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=/home/workspace/valgrind-out.txt /home/workspace/a.out
// --leak-check [summary, full]
// --show-leak-kinds [definite, indirect, possible, reachable, all, none]
// --track-origins : can be used to check where uninitialized values come from

#include<iostream>
#include<stdlib.h>

class MyClass{
    private:
        int num;

    public:

        void* operator new[](size_t size)
        {
            std::cout<<"Allocating " << size << " memory\n";
            void* p = malloc(size);

            return p;
        }

        void operator delete[](void* p)
        {
            std::cout<<"Allocated memory is being freed\n";
            free(p);
        }
};

int main()
{
    MyClass* m = new MyClass[3]();
    delete[] m;
}