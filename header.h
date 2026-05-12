#ifndef HEADER_H
#define HEADER_H
#include<vector>;
#include<iostream>;
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
class schedular {};


#endif
