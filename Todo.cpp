#include <iostream>
#include <string>
using namespace std;

void print_tasks(string tasks[], int task_count)
{
    cout << "Tasks To Do! " << endl;
    cout << "--------------------------------" << endl;
    for (int i = 0; i < task_count; i++)
    {
        cout << "Task " << i << " : " << tasks[i] << endl;
    }
    cout << "--------------------------------" << endl;
}

int main()
{
    system("color B");
    string tasks[10] = {""};
    // counter var -> know how many tasks we have
    int task_count = 0;

    int option = -1;
    while (option != 0)
    {
        // making menu
        cout<<endl;
        cout << "--- To Do List ---" << endl;
        cout << "1 - To Add New Task" << endl;
        cout << "2 - To View Tasks" << endl;
        cout << "3 - To Delete Tasks" << endl;
        cout << "0 - Terminate The Program" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
        {
            if (task_count > 9)
            {
                cout << "```Task List Is Full```" << endl;
            }
            else
            {
                cout << "Enter A New Task: ";
                cin.ignore();
                getline(cin, tasks[task_count]);
                task_count++;
            }
            break;
        }
        case 2:
        {
            system("cls");
            print_tasks(tasks, task_count);
            break;
        }
        case 3:
        {
            system("cls");
            print_tasks(tasks,task_count);
            int del_task = 0;
            cout<<"Enter The Task To Delete: ";
            cin>>del_task;

            if(del_task<0 || del_task>9)
            {
                cout<<"You Entered Invalid Task No."<<endl;
                break;
            }
            for (int i = del_task; i < task_count; i++)
            {
                tasks[i] = tasks[i + 1];
            }
            task_count = task_count - 1;
            break;
        }
        case 0:
        {
            cout<<"Terminating The Program - -- ------ -- -"<<endl;
            break;
            default:
            cout<<"You Entered Invalid Value!"<<endl;
        }
        }
    }

    return 0;
}