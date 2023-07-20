#ifndef EMPLOYEE
#define EMPLOYEE

#include "Worker.h"

class Employee: public Worker 
{
public:
    Employee(int _id, std::string _name, int _DepartID):Worker(_id,_name,_DepartID) {}
    virtual std::string GetDepartmentName();
    virtual std::string GetDepartmentWork();
};

#endif