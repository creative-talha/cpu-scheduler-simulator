#include"header.h"
void RoundRobin::schedule(std::vector<process>& p) {
    std::queue<process*> readyQueue;
    int i = 0;
    int j = 0;

    while (!readyQueue.empty() || i < p.size()) {

        while (i < p.size() && p[i].arrival_time <= time)
        {
            readyQueue.push(&p[i]);
            i++;
        }



        if (readyQueue.empty()) {
            time++;
            continue;
        }

        process* temp = running_queue(readyQueue.front(), readyQueue);


        while (i < p.size() && p[i].arrival_time <= time)
        {
            readyQueue.push(&p[i]);
            i++;
        }
        if (temp->remaining_time != 0) {
            readyQueue.push(temp);
        }



    }
}

process* RoundRobin::running_queue(process* p, std::queue<process*>& queue) {
    queue.pop();
    //running the process 


    int execution_time = std::min(p->remaining_time, quantum_time);
    p->remaining_time -= execution_time;
    time += execution_time;

    if (p->remaining_time == 0) {
        p->completion_time = time;
        p->turnaround_time = p->completion_time - p->arrival_time;
        p->waiting_time = p->turnaround_time - p->brust_time;
    }

    return p;
}


