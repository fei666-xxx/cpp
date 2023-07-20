#include<iostream>
#include<string>

class Person
{
    friend int main();
    friend std::ostream& operator<<(std::ostream& cout, Person& p);
    //friend Person& operator++(Person& p);
    //friend Person operator++(Person& p, int);

private:

    int age=0;
    std::string name="";
    int* tall;

public:
    Person();

    Person(int _age, std::string _name, int _tall);

    Person(const Person& p);

    Person operator+(Person& p);

    Person& operator++();

    Person operator++(int);

    Person& operator=(const Person& p);

    bool operator==(const Person& p);

    void operator()();
};

Person::Person(): tall(NULL) {}

Person::Person(int _age, std::string _name, int _tall):age(_age),name(_name), tall(new int(_tall)) {}

Person::Person(const Person& p)
{
    this->tall =  new int(*(p.tall));
}

Person Person::operator+(Person& p)
{
    Person temp;
    temp.age = this->age + p.age;
    temp.name = this->name + p.name;
    return temp;
}

Person& Person::operator++()
{
    this->age++;
    return *this;
}

Person Person::operator++(int)
{
    Person temp = *this;
    this->age++;
    return temp;
}

Person& Person::operator=(const Person& p)
{
    this->age = p.age;
    this->name = p.name;
    if(this->tall!=NULL) *this->tall = *p.tall;
    else this->tall = new int(*p.tall);
    return *this;
}

bool Person::operator==(const Person& p)
{
    if(this->age==p.age && this->name==p.name && *this->tall==*p.tall) return true;
    return false;
}

void Person::operator()()
{
    std::cout << this->name << ":" << this->age << " " << *this->tall << std::endl;
}

/*
Person operator+(Person& a, Person& b)
{
    Person temp;
    temp.age = a.age + b.age;
    temp.name = a.name + b.name;
    return temp;
}

Person& operator++(Person& p)
{
    p.age++;
    return p;
}

Person operator++(Person& p, int)
{
    Person temp = p;
    p.age++;
    return temp;
}

*/

std::ostream& operator<<(std::ostream& cout, Person& p)
{
    cout << p.age << " " << p.name;
    return cout;
}

int main()
{

    Person p1(18,"guo",1);
    Person p2(5,"feifei",2);    

    Person p3 = p1+p2;

    p1 = p3 = p2;

    *p3.tall = 4;
    *p1.tall = 5;

    std::cout << *p3.tall << std::endl;
    std::cout << *p2.tall << std::endl;
    std::cout << *p1.tall << std::endl;
    std::cout << (p1==p2) << std::endl;
    p3();
    return 0;
} 