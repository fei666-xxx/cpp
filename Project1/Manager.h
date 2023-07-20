#ifndef MANAGER
#define MANAGER

#include "Worker.h"

class Manager: public Worker 
{
public:
    Manager(int _id, std::string _name, int _DepartID):Worker(_id,_name,_DepartID) {}
    virtual std::string GetDepartmentName();
    virtual std::string GetDepartmentWork();
};

#endif