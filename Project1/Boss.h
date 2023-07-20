#ifndef BOSS
#define BOSS

#include "Worker.h"

class Boss: public Worker 
{
public:
    Boss(int _id, std::string _name, int _DepartID):Worker(_id,_name,_DepartID) {}
    virtual std::string GetDepartmentName();
    virtual std::string GetDepartmentWork();
};

#endif