#ifndef MYARRAY
#define MYARRAY

#include<iostream>

template<class T>
class MyArray
{
private:
    T* arr;
    int capcity;
    int size;

public:
    MyArray(int capcity)
    {
        std::cout << "myarray有参构造函数调用" << std::endl;
        this->capcity = capcity;
        this->size = 0;
        this->arr = new T[capcity];
    }

    MyArray(const MyArray& arr)
    {
        std::cout << "myarray拷贝构造函数调用" << std::endl;
        this->capcity = arr.capcity;
        this->size = arr.size;
        this->arr = new T[arr.capcity];
        for(int i=0;i<arr.size;i++)
        {
            this->arr[i] = arr.arr[i];
        }
    }

    MyArray& operator=(const MyArray& arr)
    {
        std::cout << "myarray operator=函数调用" << std::endl;
        this->capcity = arr.capcity;
        this->size = arr.size;
        if(this->arr!=NULL)
        {
            delete[] this->arr;
            this->arr=NULL;
        }
        this->arr = new T[arr.capcity];
        for(int i=0;i<arr.size;i++)
        {
            this->arr[i] = arr.arr[i];
        }
        return *this;
    }

    ~MyArray()
    {
        std::cout << "myarray析构函数调用" << std::endl;
        if(arr!=NULL)
        {
            delete[] arr;
            arr = NULL;
        }
    }

    MyArray& PushBack(const T& data)
    {
        if(this->size>=this->capcity)
        {
            T* temp = new T[this->capcity * 2];
            for(int i=0;i<this->size;i++)
            {
                temp[i] = this->arr[i];
            }
            this->capcity *= 2;
            delete[] this->arr;
            this->arr = temp;
        }

        this->arr[this->size++] = data;
        return *this;
    }

    MyArray& PopBack()
    {
        if(this->size>0)
        {
            this->size--;
        }

        return *this;
    }

    T& operator[](int index)
    {
        return this->arr[index];
    }

    int GetCapcity()
    {
        return this->capcity;
    }

    int GetSize()
    {
        return this->size;
    }

};

#endif