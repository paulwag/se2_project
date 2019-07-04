#ifndef CALENDER_MANAGER_H
    #define CALENDER_MANAGER_H

    #include <vector>
    #include "controller_intf.h"
    #include "timeline.h"

    using namespace std;

    int calc_id(tdate date);    // Prototyp, wird auch im output_controller benoetigt


    class calender_manager: public controller_intf
    {
        calender_manager() : calender_manager("calender_manager") {}
        calender_manager(string n) : controller_intf(n) {}

        calender_manager(const calender_manager& orig) = delete;
        const calender_manager& operator= (const calender_manager& orig) = delete;

        static calender_manager cm_instance;

        vector<timeline *> timelines;


        public:
            static calender_manager& get_instance();

            void start();
            void stop(bool exit = false);

            vector<timeline *> get_timelines() const {return timelines;}

            void updateTimelines(task *new_task);
    };

#endif
