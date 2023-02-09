#include <iostream>
#include <vector>
#include <map>
#include <ctime>

bool check_date(std::string* s){
    if(s->length() != 10) return false;
    if ((*s)[4] != '/' || (*s)[7] != '/') return false;
    for (auto c: {0,1,2,3,5,6,8,9})
    {
        if (!std::isdigit((*s)[c])) return false;
    }
    if(std::stoi(s->substr(5,2)) < 1 || std::stoi(s->substr(5,2)) > 12) return false;
    if(std::stoi(s->substr(8,2)) < 1 || std::stoi(s->substr(8,2)) > 31) return false;
    return true;
}

int main() {

    std::string name, birthday;
    std::map<std::string,std::string> list;
    int i = 0;

    std::time_t time = std::time(nullptr);
    char currData[10];
    std::strftime(currData, std::size(currData), "%m/%d", std::localtime(&time));
    std::cout << "Current month/day:"<< currData << std::endl;

    for(;;){

        std::cout << "Enter name:";
        std::cin >> name;
        if(name == "end") break;

        std::cout << "Enter birthday (format YYYY/MM/DD):";
        std::cin >> birthday;
        while(!check_date(&birthday)){
            std::cout << "Format incorrect! Enter again:";
            std::cin >> birthday;
        }

        list.insert(std::pair<std::string,std::string>(birthday.substr(5,5) + ":" + std::to_string(i++),name));
        /*std::cout << list.size() << std::endl;
        for (auto & it : list) {
            std::cout << it.first << " " << it.second << std::endl;
        }*/
    }

    std::cout << "Soon birthday:" << std::endl;
    bool birthdayFind = false;
    for(auto & it : list){
        if((it.first).substr(0,5) == currData){
            std::cout   << (it.first).substr(0,5) << " " << it.second\
                        << ". This event is today!!!" << std::endl;
            birthdayFind = true;
        }
        else if((it.first).substr(0,5) > currData && !birthdayFind){
            std::cout << (it.first).substr(0,5) << " " << it.second;
            birthdayFind = true;
            break;
        }
    }

    if(!birthdayFind) std::cout << "No more birthday this year!" << std::endl;

    return 0;
}
