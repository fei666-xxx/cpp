#include<iostream>

#include "MyArray.hpp"


int main()
{
    MyArray<int> arr(5);
    for(int i=0;i<6;i++)
    {
        arr.PushBack(i+1);
    }

    arr.PopBack();

    int a = 20;
    arr.PushBack(a);
    arr[5] = 10;

    std::cout << "a:" << a << std::endl;

    for(int i=0;i<arr.GetSize();i++)
    {
        std::cout << arr[i] << std::endl;
    }

    return 0;
} 