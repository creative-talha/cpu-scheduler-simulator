
#include"header.h"

void sorting(std::vector<process>& p) {
    int i = 1;
    int j = 0;
    int size = p.size();

    while (j < size) {
        i = j + 1;
        while (i < size) {
            if (p[i].arrival_time < p[j].arrival_time) {
                std::swap(p[j], p[i]);
            }
            i++;
        }
        j++;
    }
}