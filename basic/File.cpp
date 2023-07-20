#include<iostream>
#include<string>
#include<fstream>

class Person
{
private:
    char* name;
    int age;
public:
    Person() {}
    Person(char* _name, int _age):name(_name),age(_age) {}
    char* GetName() {return name;}
    int GetAge() {return age;}
    ~Person()
    {
        std::cout <<"person析构"<< std::endl;
    }
};

int main()
{
    char name[] = "guohanfei";
    Person person(name,23);
    std::ofstream ofs;
    ofs.open("E:\\mixed\\cpp\\Person.txt",std::ios::out | std::ios::binary);
    ofs.write((const char*)&person, sizeof(Person));
    ofs.close();

    std::ifstream ifs;
    ifs.open("E:\\mixed\\cpp\\Person.txt",std::ios::in | std::ios::binary);
    if(!ifs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return 0;
    }
    Person p;
    ifs.read((char*)&p, sizeof(Person));
    ifs.close();
    std::cout << std::string(p.GetName())<< std::endl;
    std::cout << p.GetAge() << std::endl;
    return 0;
}