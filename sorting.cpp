#include<iostream>
#include"header.h"

void helper_class::sorting(std::vector<process>& p) {
    std::sort(p.begin(), p.end(), [](const process& a, const process& b) {
        return a.get_arrival_time() < b.get_arrival_time();
        });

}