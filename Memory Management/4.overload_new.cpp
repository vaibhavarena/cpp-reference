#include<iostream>
#include<stdlib.h>
#include<string.h>

class myClass
{
    private:
        int number;
        std::string a;
    public:

        void* operator new(size_t s)
        {
            std::cout << "new: Allocating " << s << " bytes of memory" << std::endl;
            void* p = malloc(s);
            return p;
        }

        void operator delete(void* p)
        {
            std::cout << "delete: Memory is freed again " << std::endl;            
            free(p);
        }
};

int main()
{
    myClass *a = new myClass();
    delete a;
}
