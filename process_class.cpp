#include"header.h"

//constructor
process::process(std::string Id, int at, int bt)
    : id(Id),
    arrival_time(at),
    burst_time(bt),
    remaining_time(bt),
    completion_time(0),
    waiting_time(0),
    turnaround_time(0)
{
}

//getters
int process::get_arrival_time() const {
    return arrival_time;
}

std::string process::get_id() const {
    return id;
}

int process::get_burst_time() const {
    return burst_time;
}

int process::get_completion_time() const {
    return completion_time;
}

int process::get_waiting_time() const {
    return waiting_time;
}

int process::get_turnaround_time() const {
    return turnaround_time;
}

int process::get_remaining_time() const {
    return remaining_time;
}

//setters
void process::set_completion_time(int ct) {
    completion_time = ct;
}


//execution functions
void process::execute(int execution_time) {
    remaining_time -= execution_time;
}

void process::calculate_metrics() {

    turnaround_time = completion_time - arrival_time;

    waiting_time = turnaround_time - burst_time;
}