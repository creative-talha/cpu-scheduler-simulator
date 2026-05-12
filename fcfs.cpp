#include"header.h"

void fcfs::schedule(std::vector<process>& p) {
    int size = p.size();
    int i = 0;
    int loop_counter = 0;
    while (loop_counter < p.size())
    {
        if (time >= p[i].arrival_time) {
            time_start = time;
            time_finished = time_start + p[i].brust_time;
            time += p[i].brust_time;
            std::cout << p[i].id << " Started:" << time_start << " Finished:" << time_finished << std::endl;
            i++;
        }
        else {
            std::cout << "CPU idle at: " << time << std::endl; time++;
        }
        if (i == p.size())
            break;
        loop_counter++;
    }



};
