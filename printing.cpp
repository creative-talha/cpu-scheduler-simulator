#include"header.h"
#include<iomanip>




void helper_class::printer(std::vector<process>& p) {


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
        << std::setw(05) << "TAT"
        << std::setw(5) << "|" << std::endl;
    for (int i = 0;i < p.size();i++)
    {

        std::cout << std::setfill('-') << std::setw(61) << std::endl;
        std::cout << "\n";
        std::cout << std::setfill(' ') << std::setw(5) << p[i].get_id()
            << std::setw(5) << "|"
            << std::setw(5) << p[i].get_arrival_time()
            << std::setw(5) << "|"
            << std::setw(5) << p[i].get_burst_time()
            << std::setw(5) << "|"
            << std::setw(05) << p[i].get_completion_time()
            << std::setw(5) << "|"
            << std::setw(5) << p[i].get_waiting_time()
            << std::setw(5) << "|"
            << std::setw(5) << p[i].get_turnaround_time()
            << std::setw(5) << "|" << std::endl;

    }

}

void helper_class::chart_printing(std::vector<std::string> process, std::vector<int> time) {
    //top line
    for (int i = 0; i < process.size(); i++) {
        std::cout << "| " << process[i] << " ";
    }
    std::cout << "|" << std::endl;

    //bottom line
    for (int i = 0; i < time.size(); i++) {
        std::cout << time[i] << "\t";
    }
}