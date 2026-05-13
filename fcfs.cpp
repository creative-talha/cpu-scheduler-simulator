#include"header.h"

void fcfs::schedule(std::vector<process>& p) {
    int size = p.size();
    int i = 0;
    int loop_counter = 0;
    while (i < p.size())
    {
        //checking is there are any more processes 
        if (i == p.size())
            break;

        //if the process has arrived and cpu is free
        if (time >= p[i].arrival_time) {
            time_start = time;
            time_finished = time_start + p[i].brust_time;
            time += p[i].brust_time;
            p[i].completion_time = time_finished;
            p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
            p[i].waiting_time = p[i].turnaround_time - p[i].brust_time;
            i++;
        }

        //if process hasn,t arrived and cpu is free 
        else {
            std::cout << "CPU idle at: " << time << std::endl; time++;
        }

    }



};
