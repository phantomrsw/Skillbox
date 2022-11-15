#include <iostream>
#include <fstream>

int main() {
    std::ifstream file;
    std::string path = "../testfile.txt";

    std::cout << "Enter path to file:";
    std::cin >> path;

    file.open(path,std::ios::binary);

    if(!file.is_open()) {
        std::cout << "Fail! File not exist!";
        return 1;
    }

    char buffer[80];
    while (!file.eof()){
        file.read(buffer,80);
        for(int i = 0; i < file.gcount(); i++) std::cout << buffer[i];
    }

    file.close();
    return 0;
}
