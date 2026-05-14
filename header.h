#ifndef HEADER_H
#define HEADER_H
//includings
#include<vector>
#include<iostream>
#include <algorithm> 
#include<queue>

//process class
class process {
public:
    std::string id;
    int arrival_time, brust_time, completion_time, waiting_time, turnaround_time, remaining_time;


    process(std::string Id, int at, int bt) : arrival_time(at), brust_time(bt), id(Id), remaining_time(brust_time), completion_time(0), waiting_time(0), turnaround_time(0) {}
}
;

//sorting function
void sorting(std::vector<process>& p);
//printing function
void printer(std::vector<process>&);

//schedular class
class schedular {
public:
    virtual void schedule(std::vector<process>&) = 0;
};

//fcfs algorithm
class fcfs :public schedular {
    int time;
    int time_start, time_finished;
public:
    fcfs() :time(0), time_start(0), time_finished(0) {}
    void schedule(std::vector<process>& p) override;



};

//roundrobin function
class RoundRobin :public schedular {
    int time;
    int quantum_time;

public:

    RoundRobin(int QUANTUM_TIME) :time(0), quantum_time(QUANTUM_TIME) {}

    void schedule(std::vector<process>&)override;
    process* running_queue(process*, std::queue<process*>&);

    int gettime() {
        return time;
    }

    int get_Quantumtime() {
        return quantum_time;
    }
};


#endif
