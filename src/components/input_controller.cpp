#include <iostream>
#include "singletons.h"

using namespace std;

int check_task_parameter(string title, string description);



// /////////////////////////////////////////////////////////////////////////// Singleton Stuff
input_controller input_controller::ic_instance;
input_controller& input_controller::get_instance()
{
    return ic_instance;
}


// /////////////////////////////////////////////////////////////////////////// Start | Stop
void input_controller::start()
{
    if (getStarted())
        return;

    setStarted(true);

    cout << getName() << " gestartet" << endl;
}

void input_controller::stop(bool exit)
{
    if (!getStarted())
        return;

    setStarted(false);

    cout << getName() << " beendet" << endl;
}


// /////////////////////////////////////////////////////////////////////////// Methods
int input_controller::set_task_parameter(string title, string description, int hour, int minute, int day, int month, int year)
{
    if (check_task_parameter(title, description))
        return -1;

    task_title = title;
    task_description = description;
    task_date.set_date(day, minute, year);
    task_time.set_time(hour, minute);

    return 0;
}

void input_controller::button_pressed(int button)
{
    switch(button)
    {
        case BUT_CREATE:    tm_c.createTask(task_title, task_description, task_date, task_time);
                            break;
        case BUT_PRINT:     tm_c.printTasks();
                            break;
    }
}


// /////////////////////////////////////////////////////////////////////////// Functions
int check_task_parameter(string title, string description)
{
    int err = 0;

    if (title == "")
    {
        cout << "title input error" << endl;
        err = -1;
    }

    if (description == "")
    {
        cout << "description input error" << endl;
        err = -1;
    }

    return err;
}
