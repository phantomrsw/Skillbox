#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file;
    std::string path = "../testfile.png";

    std::cout << "Enter path for png file:";
    std::cin >> path;

    file.open(path,std::ios::binary);

    if(!file.is_open()){
        std::cout << "Fail! File not exist!";
        return 1;
    }

    if("png" != path.substr(path.length() - 3, 3)){
        std::cout << "Fail! Incorrect extension!";
        return 2;
    }

    char buffer[4];
    file.read(buffer,4);

    if((int)buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G')
        std::cout << "Yes, this is file is png!";
    else
        std::cout << "No, this file not png!";

    return 0;
}
