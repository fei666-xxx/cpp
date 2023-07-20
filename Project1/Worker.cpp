#include<iostream>
#include "Worker.h"

Worker::Worker(int _id, std::string _name, int _DepartID):ID(_id),name(_name),DepartID(_DepartID) {}

void Worker::ShowInfo()
{
    std::cout << ID << "\t" 
              << name << "\t" 
              << GetDepartmentName() << "\t"
              << GetDepartmentWork() << "\n";
}

int Worker::GetID()
{
    return ID;
}

std::string Worker::GetName()
{
    return name;
}

int Worker::GetDepartID()
{
    return DepartID;
}