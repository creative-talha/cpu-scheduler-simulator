#include"header.h"
#include<iostream>
int main() {

    std::cout << "=================================" << std::endl;
    std::cout << "  CPU SCHEDULER SIMULATOR  " << std::endl;
    std::cout << "=================================" << std::endl;
    //number of processess
    int pro;
    while (true) {
        std::cout << "Enter Number of Processess : ";
        std::cin >> pro;
        std::cout << "=================================\n";
        if (std::cin.fail() || pro <= 0 || std::cin.peek() != '\n') {

            std::cout << "Invalid Input!!!Please enter valid input!!!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            break;
        }
    }
    std::vector<process>p;
    for (int i = 0;i < pro;i++) {
        std::string id;
        int at, bt;
        std::cout << "Enter details for Process " << i + 1 << std::endl;
        std::cout << "=================================\n";
        // process id
        while (true) {
            std::cout << "Enter Process ID : ";
            std::cin >> id;
            if (id.empty()) {
                std::cout << "Invalid Input!!!Please Enter Valid Input" << std::endl;
            }
            else {
                break;
            }

        }
        //Arrival time
        while (true)
        {
            std::cout << "Enter Arrival Time of Process : ";
            std::cin >> at;
            if (std::cin.fail() || at < 0) {
                std::cout << "Invalid Input!!! Please Enter Valid Input" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            else {
                break;
            }
        }
        //burst time
        while (true) {
            std::cout << "Enter Burst Time of Process : ";
            std::cin >> bt;
            if (std::cin.fail() || bt <= 0) {
                std::cout << "Invalid Input!!! Please Enter Valid Input" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            else {
                break;
            }
        }

        p.push_back(process(id, at, bt));
    }

    int choice;
    while (true)
    {
        std::cout << "\n========================================\n";
        std::cout << "1. FCFS\n";
        std::cout << "2. Round Robin\n";
        std::cout << "3. SJF\n";
        std::cout << "========================================\n";
        std::cout << "Enter Choice : ";
        std::cin >> choice;
        if (std::cin.fail() || choice <= 0 || choice > 3) {
            std::cout << "Invalid Input!!! Please Enter Valid Input" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');

        }
        else {
            break;
        }
    }
    //fcfs
    if (choice == 1) {
        fcfs f;
        f.sorting(p);
        f.schedule(p);
        f.printer(p);
    }
    // RR
    else if (choice == 2) {
        int quantum;
        while (true) {
            std::cout << "Enter Quantum Time: ";
            std::cin >> quantum;
            if (std::cin.fail() || quantum <= 0) {
                std::cout << "Invalid Input!!! Please Enter Valid Input" << std::endl;
                std::cin.clear();
                std::cin.ignore(1000, '\n');

            }
            else {
                break;
            }
        }
        RoundRobin r(quantum);
        r.sorting(p);
        r.schedule(p);
        r.printer(p);
        std::cout << "\n\n";
        r.chart_printing(gantt_process, gantt_time);
    }
    //SJF
    else {
        sjf s;
        s.sorting(p);
        s.schedule(p);
        s.printer(p);
    }

    return 0;
}

