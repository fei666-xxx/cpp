#include<iostream>
#include<vector>
#include<string>

template<typename T>
void Swap(T& a, T& b)
{
    T temp=a;
    a=b;
    b=temp;
}

template<typename NameType, typename AgeType>
class Person
{
public:
    NameType name;
    AgeType age;

    Person(NameType _name, AgeType _age):name(_name), age(_age) {}

    void ShowInfo()
    {
        std::cout << this->name << ":" << this->age << std::endl;
    }
};

int main()
{
    // int a=3,b=4;
    // Swap(a,b);
    // std::cout << a << " " << b << std::endl;

    // double c=3.2,d=4.6;
    // Swap(c,d);
    // std::cout << c << " " << d << std::endl;

    Person<std::string, int> person("guohanfei",23);
    person.ShowInfo();

    return 0;
}