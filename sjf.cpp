#include "header.h"
#include <climits>

void sjf::schedule(std::vector<process>& p) {


    // array for number of procceses completed
    std::vector<bool> completed(p.size(), false);

    int completed_process = 0;


    while (completed_process < p.size()) {
        // store index of short process
        int idx = -1;
        // for INT_MAX we uses climits header libraray
        int min_bt = INT_MAX; //minimum bt

        for (int i = 0; i < p.size(); i++) {

            if (p[i].get_arrival_time() <= current_time &&
                !completed[i] &&
                p[i].get_burst_time() < min_bt) {

                min_bt = p[i].get_burst_time();
                idx = i;
            }
        }

        if (idx == -1) {
            current_time++;
            continue;
        }

        current_time += p[idx].get_burst_time();

        p[idx].set_completion_time(current_time);

        p[idx].calculate_metrics();

        completed[idx] = true;
        completed_process++;
    }
}