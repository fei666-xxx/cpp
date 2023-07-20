#include<iostream>
#include "WindowsManager.h"

bool cmp1(Worker* a, Worker* b)
{
    return a->GetID() < b->GetID();
}

bool cmp2(Worker* a, Worker* b)
{
    return a->GetID() > b->GetID();
}

void WindowsManager::ShowMenu()
{
    std::cout << "******************************************************************" << std::endl;
    std::cout << "*************  Welcome To Workers Management System  *************" << std::endl;
    std::cout << "******************************************************************" << std::endl;
    std::cout << "************************  00 Exit System  ************************" << std::endl;
    std::cout << "************************  01 Add Worker  *************************" << std::endl;
    std::cout << "************************  02 Show Worker  ************************" << std::endl;
    std::cout << "************************  03 Delete Worker  **********************" << std::endl;
    std::cout << "************************  04 Change Worker  **********************" << std::endl;
    std::cout << "************************  05 Search Worker  **********************" << std::endl;
    std::cout << "************************  06 Sort Worker  ************************" << std::endl;
    std::cout << "************************  07 Clear All  **************************" << std::endl;
    std::cout << "******************************************************************" << std::endl;
}

WindowsManager::WindowsManager()
{
    std::ifstream ifs;
    ifs.open(FILENAME, std::ios::in);
    if(!ifs.is_open())
    {
        //std::cout << "the file does not exist!" << std::endl;
        this->num_workers = 0;
        this->workers = NULL;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if(ifs.eof())
    {
        //std::cout << "the file is empty!" << std::endl;
        this->num_workers = 0;
        this->workers = NULL;
        ifs.close();
        return;
    }
    ifs.close();
    ifs.open(FILENAME, std::ios::in);

    ifs >> this->num_workers;
    //::cout << this->num_workers << std::endl;
    this->workers = new Worker*[this->num_workers];

    int c_id;
    std::string c_name;
    int c_departID;

    int index=0;
    while(ifs>>c_id>>c_name>>c_departID)
    {
        switch (c_departID)
        {
        case 1:
            workers[index++] = new Employee(c_id,c_name,c_departID);
            break;
        case 2:
            workers[index++] = new Manager(c_id,c_name,c_departID);
            break;
        case 3:
            workers[index++] = new Boss(c_id,c_name,c_departID);
            break;
        
        default:
            std::cout << "there is wrong DepartID at record " << index+1 << "!" << std::endl;
            system("pause");
            exit(0);
            break;
        }
    }

}

void WindowsManager::Exit()
{
    std::cout << "Welcome to use again!" << std::endl;
    system("pause");
    exit(0);
}

void WindowsManager::AddWorker()
{
    std::cout << "please input the number of new workers" << std::endl;
    int num_add;
    std::cin >> num_add;
    if(num_add>0)
    {
        int new_num = this->num_workers + num_add;
        Worker** newspace = new Worker*[new_num];
        for(int i=0;i<this->num_workers;i++)
        {
            newspace[i] = workers[i];
        }
        for(int i=0;i<num_add;i++)
        {
            int c_id;
            std::string c_name;
            int c_departID;
            std::cout << "please input the id of worker" << i+1 << std::endl;
            std::cin >> c_id;
            std::cout << "please input the name of worker" << i+1 << std::endl;
            std::cin >> c_name;
            std::cout << "please input the departID of worker" << i+1 << std::endl;
            std::cout << "1 Employee" << std::endl;
            std::cout << "2 Manager" << std::endl;
            std::cout << "3 Boss" << std::endl;
            std::cin >> c_departID;
            Worker* c_worker = NULL;
            switch (c_departID)
            {
            case 1:
                c_worker = new Employee(c_id,c_name,c_departID);
                break;

            case 2:
                c_worker = new Manager(c_id,c_name,c_departID);
                break;

            case 3:
                c_worker = new Boss(c_id,c_name,c_departID);
                break;
            
            default:
                std::cout << "Illegal input!" << std::endl;
                break;
            }
            newspace[num_workers+i] = c_worker;  
        }
        workers = newspace;
        num_workers = new_num;
        std::cout << "Success!" << std::endl;
        Save();
        system("pause");
        system("cls");
    }
    else
    {
        std::cout << "Illegal input!" << std::endl;
        system("pause");
        system("cls");
    }
}

void WindowsManager::Save()
{
    std::ofstream ofs;
    ofs.open(FILENAME, std::ios::out);

    if(this->num_workers>0) ofs << this->num_workers << "\n";

    for(int i=0;i<num_workers;i++)
    {
        ofs << workers[i]->GetID() << "\t"
            << workers[i]->GetName() << "\t"
            << workers[i]->GetDepartID() << "\n";
    }
    ofs.close();
}

void WindowsManager::ShowAll()
{
    for(int i=0;i<num_workers;i++)
    {
        workers[i]->ShowInfo();
    }
    system("pause");
    system("cls");
}

void WindowsManager::DeleteWorker()
{
    int c_id;
    std::cout << "please input the ID of the worker" << std::endl;
    std::cin >> c_id;

    int index=-1;
    for(int i=0;i<num_workers;i++)
    {
        if(workers[i]->GetID()==c_id)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        std::cout << "the worker with ID " << c_id << " does not exist!" << std::endl;
        system("pause");
        system("cls");
        return;
    }
    delete workers[index];
    for(int i=index; i<num_workers-1;i++)
    {
        workers[i] = workers[i+1];
    }
    this->num_workers--;
    this->Save();
    std::cout << "Successfully deleted! " << std::endl;
    system("pause");
    system("cls");
}

void WindowsManager::ChangeWorker()
{
    int c_id;
    std::cout << "please input the ID of the worker" << std::endl;
    std::cin >> c_id;

    int index=-1;
    for(int i=0;i<num_workers;i++)
    {
        if(workers[i]->GetID()==c_id)
        {
            index=i;
            break;
        }
    }
    if(index==-1)
    {
        std::cout << "the worker with ID " << c_id << " does not exist!" << std::endl;
        system("pause");
        system("cls");
        return;
    }
    
    std::string c_name;
    int c_departID;
    std::cout << "please input the id of worker" << std::endl;
    std::cin >> c_id;
    std::cout << "please input the name of worker" << std::endl;
    std::cin >> c_name;
    std::cout << "please input the departID of worker" << std::endl;
    std::cout << "1 Employee" << std::endl;
    std::cout << "2 Manager" << std::endl;
    std::cout << "3 Boss" << std::endl;
    std::cin >> c_departID;
    Worker* c_worker = NULL;
    switch (c_departID)
    {
    case 1:
        c_worker = new Employee(c_id,c_name,c_departID);
        break;

    case 2:
        c_worker = new Manager(c_id,c_name,c_departID);
        break;

    case 3:
        c_worker = new Boss(c_id,c_name,c_departID);
        break;
    
    default:
        std::cout << "Illegal input!" << std::endl;
        break;
    }

    if(c_worker!=NULL)
    {
        delete workers[index];
        workers[index] = c_worker;
    }

    this->Save();
    std::cout << "Successfully changed! " << std::endl;
    system("pause");
    system("cls");
}

void WindowsManager::SearchWorker()
{
    int choice;
    std::cout << "please input the search method" << std::endl;
    std::cout << "1 search by ID" << std::endl;
    std::cout << "2 search by name" << std::endl;
    std::cin >> choice;

    if(choice==1)
    {
        int c_id;
        std::cout << "please input the ID of the worker" << std::endl;
        std::cin >> c_id;

        int index=-1;
        for(int i=0;i<num_workers;i++)
        {
            if(workers[i]->GetID()==c_id)
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            std::cout << "the worker with ID " << c_id << " does not exist!" << std::endl;
            system("pause");
            system("cls");
            return;
        }
        workers[index]->ShowInfo();
    }
    else if(choice==2)
    {
        std::string c_name;
        std::cout << "please input the name of the worker" << std::endl;
        std::cin >> c_name;

        int index=-1;
        for(int i=0;i<num_workers;i++)
        {
            if(workers[i]->GetName()==c_name)
            {
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            std::cout << "the worker with name " << c_name << " does not exist!" << std::endl;
            system("pause");
            system("cls");
            return;
        }
        workers[index]->ShowInfo();
    }
    else
    {
        std::cout << "Illegal input!" << std::endl;
    }
    system("pause");
    system("cls");
}

void WindowsManager::SortWorker()
{
    if(this->num_workers<=1)
    {
        std::cout << "the workers list is already in order!" << std::endl;
        system("pause");
        system("cls");
        return;
    }
    int choice;
    std::cout << "please input the sort method" << std::endl;
    std::cout << "1 larger ID first" << std::endl;
    std::cout << "2 samller ID first" << std::endl;
    std::cin >> choice;

    if(choice==1)
    {
        std::sort(this->workers, this->workers+this->num_workers,cmp2);
        this->Save();
    }
    else if(choice==2)
    {
        std::sort(this->workers, this->workers+this->num_workers,cmp1);
        this->Save();
    }
    else
    {
        std::cout << "Illegal input!" << std::endl;
    }
    system("pause");
    system("cls");
}

void WindowsManager::ClearAll()
{
    int choice;
    std::cout << "are you sure to delete all data?" << std::endl;
    std::cout << "1 sure" << std::endl;
    std::cout << "2 cancel" << std::endl;
    std::cin >> choice;
    if(choice==1)
    {
        std::ofstream ofs;
        ofs.open(FILENAME, std::ios::trunc);
        ofs.close();
        for(int i=0;i<num_workers;i++)
        {
            if(workers[i]!=NULL)
            {
                delete workers[i];
                workers[i] = NULL;
            }
        }
        delete[] workers;
        this->num_workers = 0;
        workers = NULL;
    }
    system("pause");
    system("cls");
}