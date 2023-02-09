#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

#define NEW 0
#define IN_PROGRESS 1
#define COMPLETED 2

#define GET_ELAPSED_TIME(t)     ((t.timeEnd - t.timeBegin)/3600) << ":" \
                            << std::setw(2) << std::setfill('0') << (((t.timeEnd - t.timeBegin)%3600)/60) << ":" \
                            << std::setw(2) << std::setfill('0') << (((t.timeEnd - t.timeBegin)%3600)%60)

struct task_t{
    std::string name;
    int status = NEW;
    std::time_t timeBegin = 0;
    std::time_t timeEnd = 0;
};
task_t currTask;
std::vector<task_t> oldTasks;

int main() {

    std::string cmd;

    for(;;){
        std::cout << "Enter command:";
        std::cin >> cmd;
        if(cmd == "begin"){
            if(currTask.status == IN_PROGRESS){
                currTask.status = COMPLETED;
                currTask.timeEnd = std::time(nullptr);
                oldTasks.push_back(currTask);
            }
            std::cout << "Enter new task name:";
            std::cin >> currTask.name;
            currTask.status = IN_PROGRESS;
            currTask.timeBegin = std::time(nullptr);
        }
        else if(cmd == "end"){
            if(currTask.status == IN_PROGRESS){
                currTask.status = COMPLETED;
                currTask.timeEnd = std::time(nullptr);
                oldTasks.push_back(currTask);
            }
        }
        else if(cmd == "status"){

            std::cout << "+======================= Report =====================+" << std::endl;
            std::cout << "| Format: task name [elapsed time, hh:mm:ss]         |" << std::endl;
            std::cout << "+====================================================+" << std::endl;
            std::cout << "- Tasks completed: ----------------------------------" << std::endl;
            for(auto & oldTask : oldTasks){
                std::cout << oldTask.name << " [" << GET_ELAPSED_TIME(oldTask) << "]" << std::endl;
            }
            if(currTask.status == IN_PROGRESS){
                currTask.timeEnd = std::time(nullptr);
                std::cout << "- Task in progress: ---------------------------------" << std::endl;
                std::cout << currTask.name << " [" << GET_ELAPSED_TIME(currTask) << "]" << std::endl;
            }
        }
        else if(cmd == "exit"){
            exit(0);
        }
        else {
            std::cout << "Incorrect input!" << std::endl;
        }
    }

}
