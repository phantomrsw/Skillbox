#include <iostream>
#include <fstream>
#include <cstring>

int main() {
    std::cout << "====================================" << std::endl;
    std::cout << "=             Fishing              =" << std::endl;
    std::cout << "====================================" << std::endl;

    std::ifstream river;
    river.open("../river.txt");
    if(!river.is_open()){
        std::cout << "Fail open river.txt file: " << strerror(errno) << std::endl;
        return errno;
    }

    std::ofstream basket;
    basket.open("../basket.txt", std::ios::app);
    if(!basket.is_open()){
        std::cout << "Fail open basket.txt file: " << strerror(errno) << std::endl;
        return errno;
    }

    std::cout << "What fish will we catch?:";
    std::string fish;
    std::cin >> fish;

    int countFish = 0;
    while(!river.eof()){
        std::string temp;
        river >> temp;
        if(fish == temp){
            basket << temp << std::endl;
            countFish++;
        }
    }

    std::cout << "Total fish caught:" << countFish;

    river.close();
    basket.close();
    return 0;
}
