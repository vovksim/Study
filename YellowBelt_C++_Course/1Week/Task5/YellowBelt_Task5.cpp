// YellowBlt_TAsk5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include<tuple>

using namespace std;




enum class TaskStatus {
    NEW,
    IN_PROGRESS,
    TESTING,
    DONE
};


ostream& operator <<(ostream& out, const TaskStatus& status) {
    switch (status) {
    case TaskStatus::NEW: {
        out << "NEW";
    }
    case TaskStatus::IN_PROGRESS: {
        out << "IN_PROGRESS";
    }
    case TaskStatus::TESTING: {
        out << "TESTING";
    }
    case TaskStatus::DONE: {
        out << "DONE";
    }
    }
    return out;
}

using TasksInfo = map<TaskStatus, int>;


void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

class TeamTasks {
    map<string, TasksInfo> TeamTask;
public:
    
    const TasksInfo& GetPersonTasksInfo(const string& person);

    // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
    void AddNewTask(const string& person);

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count);
};


void TeamTasks::AddNewTask(const string& person) {
    ++TeamTask[person][TaskStatus::NEW];
}

const TasksInfo& TeamTasks :: GetPersonTasksInfo(const string& person) {
    return TeamTask[person];
}

tuple<TasksInfo, TasksInfo> TeamTasks::PerformPersonTasks(const string& person, int task_count) {
    TasksInfo ::iterator it = TeamTask[person].begin();
    TasksInfo movedTasksNew, staticTasks=TeamTask[person];
    for (it; it != TeamTask[person].end(); ++it) {
        if (it->first == TaskStatus::NEW) {
            int quantity = it->second;
            while (task_count>0 and quantity>0) {
                ++movedTasksNew[TaskStatus::IN_PROGRESS];
                ++TeamTask[person][TaskStatus::IN_PROGRESS];
                --TeamTask[person][TaskStatus::NEW];
                --staticTasks[TaskStatus::NEW];
                task_count--;
                quantity--;
            }
            
        }
        if (it->first == TaskStatus::IN_PROGRESS) {
            int quantity = it->second;
            while (task_count > 0 and quantity > 0) {
                movedTasksNew[TaskStatus::TESTING]++;
                ++TeamTask[person][TaskStatus::TESTING];
                --TeamTask[person][TaskStatus::IN_PROGRESS];
                --staticTasks[TaskStatus::IN_PROGRESS];
                task_count--;
                quantity--;
            }
        }
        if (it->first == TaskStatus::TESTING) {
            int quantity = it->second;
            while (task_count > 0 and quantity > 0) {
                movedTasksNew[TaskStatus::DONE]++;
                ++TeamTask[person][TaskStatus::DONE];
                --TeamTask[person][TaskStatus::TESTING];
                --staticTasks[TaskStatus::TESTING];
                task_count--;
                quantity--;
            }
        }
    }
    //TasksInfo::iterator iter = movedTasksNew.begin();
    //for (iter; iter!= movedTasksNew.end(); ++iter) {
    //    cout << iter->first << "  ;  " << iter->second << endl;
    //}
    //TeamTask[person] = movedTasksNew + staticTasks;
    return make_tuple(movedTasksNew, staticTasks);

}


int main()
{
    TeamTasks tasks;
    tasks.AddNewTask("Ilia");
    for (int i = 0; i < 3; ++i) {
        tasks.AddNewTask("Ivan");
    }
    cout << "Ilia's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << "Ivan's tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Ivan", 2);
    cout << "Updated Ivan's tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ivan's tasks: ";
    PrintTasksInfo(untouched_tasks);
   
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
