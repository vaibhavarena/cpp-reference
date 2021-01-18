// New and delete are operators while malloc and calloc are functions
#include<malloc.h>
#include<stdlib.h>
#include<string>
#include<iostream>

struct myName{
    std::string name;
    int age;

    myName(std::string n, int a){
        name = n;
        age = a;
    }
};

int main()
{
    int *p = (int*)malloc(sizeof(int));     // Use realloc in increase size of same variable
    // Re sizing the memory by shrinking size will shrink the block of memory but the data will be there and can 
    // still be used by the program and no compiler or run time error will occur or can be reclaimed by the compiler 
    // which leads to undefined behaviour
    printf("Address : %p, value : %d\n", p, *p);

    myName* v = (myName*)calloc(2, sizeof(myName));
    v[0].age = 27;
    v[0].name = "Vaibhav";

    v[1].age = 12;
    
    std::cout<<v[1].name << "a\n";   // Value in uninitialized string i.e. ""

    return 0;

    free(p);
    free(v);
}