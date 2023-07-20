#include<iostream>
#include<string>

class Person
{
public:
    int age=20;
    std::string name="person";
    static int live;

    Person()
    {
        std::cout << "构造父类" << std::endl;
    }

    ~Person()
    {
        std::cout << "销毁父类" << std::endl;
    }

}; 

class Guo: public Person
{
public:
    Guo()
    {
        std::cout << "构造子类" << std::endl;
    }

    ~Guo()
    {
        std::cout << "销毁子类" << std::endl;
    }

    std::string name="guohanfei";
};

int Person::live = 0;


class Animal
{
public:
    virtual void speak()
    {
        std::cout << "动物在说话" << std::endl;
    }
}; 

class Cat: public Animal
{
public:
    std::string name = "cat";
    void speak()
    {
        std::cout << "小猫在说话" << std::endl;
    }
    void speakCat()
    {
        std::cout << "小猫在说话" << std::endl;
    }
};

class Dog: public Animal
{
public:
    std::string name = "dog";  
    void speak()
    {
        std::cout << "小狗在说话" << std::endl;
    }
};

void DoSpeak(Animal& animal)
{
    animal.speak();
}

int main()
{
    /*
    Guo g;
    g.age = 30;
    std::cout << g.Person::name << std::endl;
    std::cout << std::a << std::endl;
    

    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
    */
    Animal* animal = new Cat;
    animal->speak();
    std::cout << sizeof(Animal) << std::endl;

    return 0;
}