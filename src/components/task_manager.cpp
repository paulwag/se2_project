#include <iostream>
#include "task_manager.h"
#include "singletons.h"
#include "task.h"


void task_manager::start()
{
    if (getStarted())
            return;

    setStarted(true);

    std::cout << getName() << " gestartet" << endl;
}



void task_manager::stop(bool exit)
{
    if (!getStarted())
            return;

    setStarted(false);

    std::cout << getName() << " beendet" << endl;
}



void task_manager::createTask()
{
    cout << "TM: Task wird erstellt..." << endl;

    vector<task *>& tasks = db_c.getTasks(); //reference to task vector
    task *newTask = new task();

    int identifier = tasks.size() + 1; //zunaechst wird der Identifier uber die Groesse des Vektors erstellt
    newTask->set_identifier(identifier);
    tasks.push_back(newTask);

    db_c.storeFile(); // Aenderungen speichern
}



void task_manager::delTask() {}
void task_manager::updateTask() {}
