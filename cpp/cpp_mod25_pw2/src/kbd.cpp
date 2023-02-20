#include <iostream>
#include "ram.h"

void input(){
    int n;
    for(int i = 0; i < 8; i++){
        std::cout << "Enter number " << i << " to RAM:";
        std::cin >> n;
        write_ram(i, n);
    }
    std::cout << "Input numbers is complete!" << std::endl;
}
