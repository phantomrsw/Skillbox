#include <fstream>
#include <iostream>
#include "ram.h"
#include <cstring>

int save(){
    std::ofstream file;
    file.open("../data.txt",std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Fail open file: " << strerror(errno) << std::endl;
        return errno;
    }

    for(int i = 0; i < 8; i++) file << read_ram(i) << " ";

    file.close();
    return errno;
}

int load(){
    std::ifstream file;
    file.open("../data.txt",std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Fail open file: " << strerror(errno) << std::endl;
        return errno;
    }

    int t;
    for(int i = 0; i < 8; i++) {
        file >> t;
        write_ram(i, t);
    }

    file.close();
    return errno;
}
