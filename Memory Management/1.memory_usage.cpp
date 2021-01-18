#include<chrono>
#include<iostream>

int main()
{
    const int size = 10000;
    static int x[size][size];

    auto t1 = std::chrono::high_resolution_clock::now();

    for(int i = 0;i<size ;i++)
    {
        for(int j = 0;j<size ;j++)
        {
            x[i][j] = i + j;
            // x[j][i] = i + j;     Represents slower speed of execution because of row major storage 
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();

    auto t3 = std::chrono::duration_cast<std::chrono::microseconds>(t2-t1).count();

    std::cout<<t3 << " microseconds\n"; 
}