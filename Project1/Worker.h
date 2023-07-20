#ifndef WORKER
#define WORKER

#include<string>

class Worker
{
protected:
    int ID;
    std::string name;
    int DepartID;

public:
    Worker(int _id, std::string _name, int _DepartID);
    void ShowInfo();
    virtual std::string GetDepartmentName()=0;
    virtual std::string GetDepartmentWork()=0;
    int GetID();
    std::string GetName();
    int GetDepartID();
};

#endif