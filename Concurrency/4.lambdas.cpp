// Lambdas - creates closure during runtime and doesn't exist itself
// Relationship between Lambdas and closure can be seen as relation between class and object

#include<iostream>
#include<thread>

int main()
{
    int id = 0;

    auto f1 = [](){std::cout<<"Function 1 has been created\n";};

    // Mutable is used so that variable in capture list can be modified
    auto f2 = [&id]() mutable {std::cout<<"The id has been incremented to " << ++id << "\n";};
    
    auto f3 = [&id](const int x) mutable {std::cout<<"The id has been incremented to " << id + x << "\n";};

    f1();
    f2();
    f3(2);
}