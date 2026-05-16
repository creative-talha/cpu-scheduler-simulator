#include"header.h"
#include<iomanip>




void helper_class::printer(std::vector<process>& p) {

    system("clear");
    std::cout << "\n\tTable:\n";
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

    //calculating avg
    double avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < p.size(); i++) {
        avg_wt += p[i].get_waiting_time();
        avg_tat += p[i].get_turnaround_time();
    }
    avg_wt /= p.size();
    avg_tat /= p.size();

    std::cout << "\n\tAverage Data:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nAverage Waiting Time    : " << avg_wt << "\n";
    std::cout << "Average Turnaround Time : " << avg_tat << "\n";
}



void helper_class::chart_printing(std::vector<std::string> process, std::vector<int> time) {

    std::cout << "\n\tGantt Chart:\n";
    // top border
    for (int i = 0; i < process.size(); i++)
        std::cout << "+-----";
    std::cout << "+" << "\n";

    // process names
    for (int i = 0; i < process.size(); i++)
        std::cout << "|  " << std::setw(2) << process[i] << " ";
    std::cout << "|" << "\n";

    // bottom border
    for (int i = 0; i < process.size(); i++)
        std::cout << "+-----";
    std::cout << "+" << "\n";

    // time labels
    std::cout << std::setw(1) << time[0];
    for (int i = 1; i < time.size(); i++)
        std::cout << std::setw(6) << time[i];
    std::cout << "\n";
}