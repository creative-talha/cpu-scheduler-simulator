#include<iostream>
#include"header.h"

void sorting(std::vector<process>& p) {
    std::sort(p.begin(), p.end(), [](const process& a, const process& b) {
        return a.arrival_time < b.arrival_time;
        });
}