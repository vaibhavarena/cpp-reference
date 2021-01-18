// Copy semantics - copying objects to other objects might end up pointing to the same location in case 
// of pointers and cause problems
// 1st method - No copying policy -> 1.Declare private members but not define them  2.Assign delete to copy constructors
#include <stdlib.h>
#include <iostream>

class noCopy
{
private:
    noCopy(const noCopy &);
    noCopy &operator=(const noCopy &);

public:
    noCopy(){};
};

class noCopyDelete
{
public:
    noCopyDelete() {}
    noCopyDelete(const noCopyDelete &) = delete;
    noCopyDelete &operator=(const noCopyDelete &) = delete;
};

// Exclusive ownership - resource handles remain with 1 object only, when assigned the previous object is set to null pointer
// and the new object is assigned the member value
class exclusiveOwner
{
private:
    int *a;

public:
    exclusiveOwner()
    {
        a = (int *)malloc(sizeof(int));
        std::cout << "Memory allocated\n";
    }
    ~exclusiveOwner()
    {
        free(a);
        std::cout << "Resource Freed\n";
    }

    exclusiveOwner(exclusiveOwner &b)
    {
        a = b.a;
        b.a = nullptr;
    }

    exclusiveOwner &operator=(exclusiveOwner &b)
    {
        a = b.a;
        b.a = nullptr;
        return *this;
    }
};

// Deep copy policy - Maintain the same value at 2 different locations to prevent conflicts
class deepCopy
{
private:
    int *val;

public:
    deepCopy(int v)
    {
        val = (int *)malloc(sizeof(int));
        *val = v;
        std::cout << "Memory allocated at " << val << "\n";
    }
    ~deepCopy()
    {
        free(val);
        std::cout << "Memory freed at " << val << "\n";
    }

    deepCopy(deepCopy &source)
    {
        val = (int *)malloc(sizeof(int));
        *val = *source.val;

        std::cout << "Resource allocated at " << val << "\n";
    }

    deepCopy &operator=(deepCopy &source)
    {
        val = (int *)malloc(sizeof(int));
        *val = *source.val;

        std::cout << "Resource allocated at " << val << "\n";

        return *this;
    }
};

// Shared policy - Maintain a counter for all objects in scope and free space only when the last element is going out of scope
class sharedPolicy
{
private:
    int *num;
    static int counter;

public:
    sharedPolicy(int val)
    {
        num = (int *)malloc(sizeof(int));
        *num = val;
        std::cout << "Shared policy - Memory allocated at : " << num << "\n";
        counter += 1;
    }
    ~sharedPolicy()
    {
        counter--;
        if (counter == 0)
        {
            free(num);
            std::cout << "Shared Policy - Memory deallocated at " << num << "\n";
        }
        else{
            std::cout<<"Resource no longer pointing to " << num << "\n";
        }
    }

    sharedPolicy(sharedPolicy &x)
    {
        num = x.num;
        counter += 1;
    }

    sharedPolicy &operator=(sharedPolicy &x)
    {
        num = x.num;
        counter += 1;
        return *this;
    }
};

int sharedPolicy::counter = 0;

int main()
{
    noCopy n;
    // noCopy m(n);    Its inaccessible to other members
    // noCopy o = n;

    noCopyDelete nd;
    // noCopyDelete md(nd);     More preferrable method as it specifies that copy constructor is not allowed
    // noCopyDelete od = nd;

    exclusiveOwner e;
    exclusiveOwner f(e);
    exclusiveOwner g(f);
    // If you free a nullptr nothing will happen, Destructors will be called at end of program and free nullptr e.a and f.a

    deepCopy de(34);
    deepCopy fe(de);
    deepCopy ge = fe;

    sharedPolicy se(23);
    sharedPolicy sf(se);
}
