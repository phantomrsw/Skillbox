#include <iostream>
#include "ram.h"

void display(){
    std::cout << "RAM content:";
    for(int i = 0; i < 8; i++) std::cout << read_ram(i) << " ";
    std::cout << std::endl;
}
