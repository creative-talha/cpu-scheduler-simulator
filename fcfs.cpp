#include"header.h"

void fcfs::schedule(std::vector<process>& p) {

    int i = 0;

    while (i < p.size())
    {


        //if the process has arrived and cpu is free
        if (current_time >= p[i].get_arrival_time()) {
            time_start = current_time;
            time_finished = time_start + p[i].get_burst_time();
            current_time += p[i].get_burst_time();
            p[i].set_completion_time(time_finished);
            p[i].calculate_metrics();
            i++;
        }

        //if process hasn,t arrived and cpu is free 
        else {
            std::cout << "CPU idle at: " << current_time << std::endl; current_time = p[i].get_arrival_time();
        }

    }



};
