#include <iostream>
#include "ram.h"

void compute(){
    int result{};
    for(int i = 0; i < 8; i++){
        result += read_ram(i);
    }
    std::cout << "Computing 8 numbers from RAM:" << result << std::endl;
}