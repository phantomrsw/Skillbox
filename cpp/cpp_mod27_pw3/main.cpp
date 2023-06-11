#include <iostream>

class Worker{
    std::string name = "Noname";
    std::string task = "None";

public:

    Worker(int n){
       name = "Worker" + std::to_string(n);
       std::cout << "Created worker with name:" << name << std::endl;
    }

    void set_task(int t){
        if(t == 1) task = "A";
        else if(t == 2) task = "B";
        else if(t == 3) task = "C";
        else task = "None";
        if(task != "None") std::cout << name << " got a task " << task << std::endl;
    }

    bool is_busy(){
        if(task != "None") return true;
        else return false;
    }
};

class Team{
    std::string managerName = "Noname";
    int managerId = 0;
    int numberWorkers;
    Worker* workers[];

public:

    Team(int n){
        managerName = "Manager" + std::to_string(n);
        managerId = n;
        std::cout << "Created team with " << managerName << std::endl;
        std::cout << "Enter number of workers in current team:";
        std::cin >> numberWorkers;
        for(int i = 0; i < numberWorkers; i++){
            workers[i] = new Worker(i);
        }
    }

    bool all_workers_busy(){
        bool busy = true;
        for(int i = 0; i < numberWorkers; i++){
            if(!workers[i]->is_busy()) busy = false;
        }
        return busy;
    }

    void assign_a_task(int n){
        std::cout << managerName << " got a task " << n << std::endl;
        std::srand(n + managerId);
        int tasksCount = std::rand() % (numberWorkers + 1);
        for(int i = 0; i < tasksCount; i++){
            for(int j = 0; j < numberWorkers; j++){
                if(!workers[j]->is_busy()){
                    std::srand(j + i);
                    int taskType = std::rand() % 3 + 1;
                    workers[j]->set_task(taskType);
                    break;
                }
            }
        }
    }

};

class Company{
    std::string bossName = "Boss";
    int numberTeams{};
    Team* teams[];

public:

    Company(){
        std::cout << "Enter number of teams in company:";
        std::cin >> numberTeams;
        for(int i = 0; i < numberTeams; i++){
            teams[i] = new Team(i);
        }
    }

    void create_task(){
        std::cout << bossName << " want created task (number):";
        int n;
        std::cin >> n;
        for(int i = 0; i < numberTeams; i++){
            teams[i]->assign_a_task(n);
        }
    }

    bool all_workers_busy(){
        bool busy = true;
        for(int i = 0; i < numberTeams; i++){
            if(!teams[i]->all_workers_busy()) busy = false;
        }
        return busy;
    }

};

int main() {
    Company* company = new Company;

    while(!company->all_workers_busy()){
        company->create_task();
    };

    delete company;
    return 0;
}
