#ifndef HEADER_H
#define HEADER_H
#include<vector>
#include<iostream>
#include <algorithm> 
//process class
class process {
public:
    std::string id;
    int arrival_time, brust_time, completion_time, waiting_time, turnaround_time;


    process(std::string Id, int at, int bt) : arrival_time(at), brust_time(bt), id(Id) {}
}
;

//sorting function
void sorting(std::vector<process>& p);

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
    fcfs(int TIME) :time(TIME), time_start(0), time_finished(0) {}
    void schedule(std::vector<process>& p) override;


};


#endif
