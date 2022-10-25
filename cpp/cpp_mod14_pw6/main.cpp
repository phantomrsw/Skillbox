#include <iostream>
#include <cmath>

int main() {

    int digits[5][5];
    int number = 0;
    int multiplier = -1;

    for(const auto & i : {0,1,2,3,4}) {
        for(const auto & j : {0,1,2,3,4}) {
            digits[i][(int)(std::pow(4,multiplier) - j * multiplier)] = number;
            number += 1;
        }
        multiplier *= -1;
    }

    for(const auto & i : {0,1,2,3,4}){
        for(const auto & j : {0,1,2,3,4}){
            std::cout << digits[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
