#include<iostream>
#include<string>
using std::cout;
using std::string;

void add(int a, int b)
{
    cout<< a + b << "\n";
}

void add(string a, string b)
{
    cout << a << " " << b << "\n";
}

int main()
{
    int a = 23, b =52;
    string c = "Mike", d = "Bandini";

    add(a,b);
    add(c,d);
}