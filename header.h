#ifndef HEADER_H
#define HEADER_H
//includings
#include<vector>
#include<iostream>
#include <algorithm> 
#include<queue>
#include <limits>
#include <string>  

//process class
class process {
private:
    std::string id;
    int arrival_time, burst_time, completion_time, waiting_time, turnaround_time, remaining_time;

public:
    process(std::string Id, int at, int bt);
    //getters
    std::string get_id() const;
    int get_arrival_time() const;
    int get_burst_time() const;
    int get_completion_time() const;
    int get_waiting_time() const;
    int get_turnaround_time() const;
    int get_remaining_time() const;
    //setters
    void set_completion_time(int ct);

    //execution functions
    void execute(int execution_time);//for RR only
    void calculate_metrics(); //used by all
};

class helper_class {

public:

    void  sorting(std::vector<process>&);
    void printer(std::vector<process>&);


};

//schedular class
class schedular {
public:
    virtual void schedule(std::vector<process>&) = 0;
};

//fcfs algorithm
class fcfs :public schedular, public helper_class {
    int current_time;
    int time_start, time_finished;
public:
    fcfs() :current_time(0), time_start(0), time_finished(0) {}
    void schedule(std::vector<process>& p) override;





};

//roundrobin function
class RoundRobin :public schedular, public helper_class {
    int current_time;
    int quantum_time;

public:
    //constructor
    RoundRobin(int QUANTUM_TIME) :current_time(0), quantum_time(QUANTUM_TIME) {}
    //schedular algo
    void schedule(std::vector<process>&)override;
    //running queue function
    process* running_queue(process*, std::queue<process*>&);

    //helper functions

    int get_time() {
        return current_time;
    }

    int get_quantumtime() {
        return quantum_time;
    }
};

// SJF Algorithm
class sjf : public schedular, public helper_class {
    int current_time;
public:
    sjf() : current_time(0) {}
    void schedule(std::vector<process>& p) override;
};


#endif
