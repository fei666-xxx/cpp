#include<iostream>
#include "WindowsManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main()
{
    WindowsManager wm;
    while(true)
    {
        wm.ShowMenu();

        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            wm.Exit();
            break;

        case 1:
            wm.AddWorker();
            break;
        
        case 2:
            wm.ShowAll();
            break;
        
        case 3:
            wm.DeleteWorker();
            break;

        case 4:
            wm.ChangeWorker();
            break;

        case 5:
            wm.SearchWorker();
            break;

        case 6:
            wm.SortWorker();
            break;

        case 7:
            wm.ClearAll();
            break;

        default:
            system("cls");
            break;
        }

    }
    return 0;
}