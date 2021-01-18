#include<iostream>
#include<string>
#include<sstream>
using std::cout;
using std::string;
using std::istringstream;

int main()
{
    string s = "1,2,3";
    istringstream my_file(s);

    int n;
    char c;
    while(my_file)
    {
        my_file >> n >> c;  // Fetches the stream like a pattern, thus 3 will not be printed
        if(my_file)
        cout<<n << c;
        else
        {
            cout<<"The string ended ";
        }
        
    }

    return 0;
}