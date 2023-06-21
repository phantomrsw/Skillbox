#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

std::mutex mutex_train;

class Train{

    std::string name;
    int travelTime{};

public:

    explicit Train(std::string &name){
        this->name = name;
        std::cout << "Enter travel time for train " << this->name << " (sec.):";
        std::cin >> travelTime;
    }

    void rides(std::vector<Train *> *ptrQueue){
        mutex_train.lock();
        std::cout << "The Train " << name << " to ride!" << std::endl;
        mutex_train.unlock();
        while(travelTime--){
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        mutex_train.lock();
        ptrQueue->push_back(this);
        std::cout << "The Train " << name << " waiting arrive!" << std::endl;
        mutex_train.unlock();
    }

    std::string get_name(){
        return name;
    }
};

class TrainStation{

    std::vector<Train *> queue;

public:

    std::vector<Train *> *ptrQueue = &queue;

    /*void add_to_queue(Train *ptr){
       queue.push_back(ptr);
    }*/
    //void (TrainStation::*ptr_add_to_queue)(Train *){&TrainStation::add_to_queue};

    void take_train(){
        for(int i = 0; i < 3; i++){
            while(queue.empty()){}
            std::cout << "Train " << queue[i]->get_name() << " arrived on Station!" << std::endl;
            std::cout << "Enter command 'depart':";
            std::string  command;
            std::cin >> command;
            while(command != "depart"){}
            std::cout << "Train " << queue[i]->get_name() << " departed from Station!" << std::endl;
        }
    }
};

class RailWays{

    TrainStation *trainStation{nullptr};
    Train *trains[3]{nullptr};

public:

    RailWays(){
        int i{};
        for(auto & train : trains){
            std::string name[3] = {"A","B","C"};
            train = new Train(name[i++]);
        }
        trainStation = new TrainStation;
    }

    ~RailWays(){
        for(auto & train : trains){
            delete train;
        }
        delete trainStation;
    }

    void run_threads(){
        std::cout << "All trains have gone!" << std::endl;
        std::vector<std::thread> threads;
        for(auto & train : trains) threads.emplace_back(&Train::rides,train,trainStation->ptrQueue);
        std::thread threadStation(&TrainStation::take_train, trainStation);
        for(auto & i : threads) i.join();
        threadStation.join();
    }
};

int main() {

    auto *railWays = new RailWays;

    railWays->run_threads();

    delete railWays;

    return 0;
}
