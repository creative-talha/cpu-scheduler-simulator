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

class helper_class {

public:

    void  sorting(std::vector<process>&);
    virtual void printer(std::vector<process>&) = 0;


};






//schedular class
class schedular {
public:
    virtual void schedule(std::vector<process>&) = 0;
};

//fcfs algorithm
class fcfs :public schedular, public helper_class {
    int time;
    int time_start, time_finished;
public:
    fcfs() :time(0), time_start(0), time_finished(0) {}
    void schedule(std::vector<process>& p) override;
    void printer(std::vector<process>&) override;




};

//roundrobin function
class RoundRobin :public schedular, public helper_class {
    int time;
    int quantum_time;

public:

    RoundRobin(int QUANTUM_TIME) :time(0), quantum_time(QUANTUM_TIME) {}

    void schedule(std::vector<process>&)override;
    process* running_queue(process*, std::queue<process*>&);
    void printer(std::vector<process>&) override;

    int gettime() {
        return time;
    }

    int get_Quantumtime() {
        return quantum_time;
    }
};

// SJF Algorithm
class sjf : public schedular{
    int current_time;
public:
    sjf(): current_time(0){}
    void schedule(std::vector<process>& p) override;
};


#endif
