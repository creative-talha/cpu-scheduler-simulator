#include"header.h"
#include<iomanip>



void printer(std::vector<process>& p) {


    //printing the main header first
    std::cout << std::setw(5) << "Process"
        << std::setw(3) << "|"
        << std::setw(05) << "AT"
        << std::setw(5) << "|"
        << std::setw(05) << "BT"
        << std::setw(5) << "|"
        << std::setw(5) << "CT"
        << std::setw(5) << "|"
        << std::setw(5) << "WT"
        << std::setw(5) << "|"
        << std::setw(10) << "TAT |" << std::endl;
    for (int i = 0;i < p.size();i++)
    {

        std::cout << std::setfill('-') << std::setw(61) << std::endl;
        std::cout << "\n";
        std::cout << std::setfill(' ') << std::setw(5) << p[i].id
            << std::setw(5) << "|"
            << std::setw(5) << p[i].arrival_time
            << std::setw(5) << "|"
            << std::setw(5) << p[i].brust_time
            << std::setw(5) << "|"
            << std::setw(05) << p[i].completion_time
            << std::setw(5) << "|"
            << std::setw(5) << p[i].waiting_time
            << std::setw(5) << "|"
            << std::setw(5) << p[i].turnaround_time
            << std::setw(5) << "|" << std::endl;

    }

}