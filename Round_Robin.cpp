#include"header.h"
void RoundRobin::schedule(std::vector<process>& p) {
    std::queue<process*> readyQueue;
    gantt_time.push_back(0);
    int i = 0;
    int j = 0;

    while (!readyQueue.empty() || i < p.size()) {

        while (i < p.size() && p[i].get_arrival_time() <= current_time)
        {
            readyQueue.push(&p[i]);
            i++;
        }



        if (readyQueue.empty()) {
            current_time++;
            continue;
        }

        process* temp = running_queue(readyQueue.front(), readyQueue);


        while (i < p.size() && p[i].get_arrival_time() <= current_time)
        {
            readyQueue.push(&p[i]);
            i++;
        }
        if (temp->get_remaining_time() != 0) {
            readyQueue.push(temp);
        }



    }
}

process* RoundRobin::running_queue(process* p, std::queue<process*>& queue) {
    queue.pop();
    //running the process 


    int execution_time = std::min(p->get_remaining_time(), quantum_time);
    p->execute(execution_time);
    current_time += execution_time;
    gantt_process.push_back(p->get_id());
    gantt_time.push_back(current_time);

    if (p->get_remaining_time() == 0) {
        p->set_completion_time(current_time);
        p->calculate_metrics();
    }

    return p;
}


