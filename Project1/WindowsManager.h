#ifndef WINDOWS_MANAGER
#define WINDOWS_MANAGER

#define FILENAME "E:\\mixed\\cpp\\Project1\\Workers.txt"

#include<algorithm>
#include<fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

class WindowsManager
{
private:
    int num_workers = 0;
    Worker**  workers = NULL;

public:
    WindowsManager();
    void ShowMenu();
    void Exit();
    void AddWorker();
    void Save();
    void DeleteWorker();
    void ChangeWorker();
    void SearchWorker();
    void SortWorker();
    void ClearAll();

    void ShowAll();
};

#endif