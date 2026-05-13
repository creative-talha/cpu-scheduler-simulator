#include"header.h"

int main() {

    std::vector<process> r{
            {"p1",0,3},
            {"p2",2,3},
            {"p3",1,3},


    };
    sorting(r);
    fcfs f;
    f.schedule(r);
    printer(r);
}
