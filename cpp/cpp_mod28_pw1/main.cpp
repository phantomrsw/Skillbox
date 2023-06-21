#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

std::mutex mutex_cout;

class Swimmer{
    std::string name = "Unknown";
    int speed{20};
    int distance{};
    int time{};

public:

    Swimmer(){
        //std::cout << "Constructor Swimmer" << std::endl;
        std::cout << "Enter name for swimmer:" ;
        std::cin >> name;
        std::cout << "Enter the speed of swimmer " << name << " (m/s):";
        std::cin >> speed;
    }

    void swimming(){
        while(distance < 100) {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            if(distance + speed > 100) distance = 100;
            else distance += speed;
            time++;
            mutex_cout.lock();
            std::cout   << "Swimmer name:" << name << " speed:" << speed
                        << " distance:" << distance << " time:" << time
                        << std::endl;
            mutex_cout.unlock();
        }
    }

    std::string get_name(){return name;}
    int get_time(){return time;}

};

class Swim{

    Swimmer* swimmers;

public:

    Swim(){
        swimmers = new Swimmer[6];
        //std::cout << "Constructor Swim" << std::endl;
    }

    ~Swim(){
        delete[] swimmers;
        //std::cout << "Destructor Swim" << std::endl;
    }

    void run(){
        std::cout << "~~~~~~~~~~~~~ Swimmers swam! ~~~~~~~~~~~~" << std::endl;
        std::vector<std::thread> treads;
        for(int i = 0; i < 6; i++) treads.emplace_back(&Swimmer::swimming,&swimmers[i]);
        for(auto& i : treads) {i.join();}
    }

    void show_result(){

        bool mask[6]{};
        int index[6]{};
        int i = 0;
        for(int j = 0; i < 6;){
            if(!mask[j]){
                int minTime = swimmers[j].get_time();
                index[i] = j;
                for(int k = j + 1; k < 6; k++){
                    if(!mask[k]){
                        if(minTime > swimmers[k].get_time()) {
                            minTime = swimmers[k].get_time();
                            index[i] = k;
                        }
                    }
                }
                mask[index[i]] = true;
                i++;
            }
            else j++;
        }

        std::string s[] = {
                {"+===========================================+\n"},
                {"| Place |          Name          |   Time   |\n"},
                {"|-------+------------------------+----------+\n"},
                {"|       |                        |          |\n"},
                {"|       |                        |          |\n"},
                {"|       |                        |          |\n"},
                {"|       |                        |          |\n"},
                {"|       |                        |          |\n"},
                {"|       |                        |          |\n"},
                {"+===========================================+\n"}};

        for(i = 0; i < 6; i++) {
            sprintf(&(s[3 + i][4]),"%d",i + 1);
            sprintf(&(s[3 + i][10]),"%s", swimmers[index[i]].get_name().c_str());
            sprintf(&(s[3 + i][35]),"%3d", swimmers[index[i]].get_time());
        }
        i = 0;
        for(const auto & e : s) std::cout << s[i++];
    }

};

int main() {

    Swim* swim = new Swim;

    swim->run();

    swim->show_result();

    delete swim;
    return 0;
}
