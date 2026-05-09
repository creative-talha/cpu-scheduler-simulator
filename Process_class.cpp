
#include"header.h"
class process {
public:
    std::string id;
    int arrival_time, brust_time, completion_time, waiting_time, turnaround_time;


    process(std::string Id, int at, int bt) : arrival_time(at), brust_time(bt), id(Id) {}
}
;