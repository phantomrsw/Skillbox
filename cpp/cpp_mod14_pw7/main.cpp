#include <iostream>
#include <vector>
#define SIZE 5

int main() {

    int world[SIZE][SIZE][10];
    int level;

    std::cout << "Enter the world matrix heights(" << SIZE << "x" << SIZE <<"):";
    for(auto & i : world){
        for(auto & j : i){
            std::cin >> level;
            while(level < 0 || level > 9){
                std::cout << "Fail! Incorrect value! Enter again:";
                std::cin >> level;
            }
            for(int k = 0; k < 10; k++) {
                if(k <= level) j[k] = level;
                else j[k] = 0;
            }
        }
    }

    while(true){
        std::cout << "Enter level world:";
        std::cin >> level;
        while(level < -1 || level > 9){
            std::cout << "Fail! Incorrect value! Enter again:";
            std::cin >> level;
        }
        if(level == -1) return 0;
        for(auto & i : world){
            for(auto & j : i){
                if (j[level]) std::cout << "1 ";
                else std::cout << "0 ";
            }
            std::cout << std::endl;
        }
    }
}
