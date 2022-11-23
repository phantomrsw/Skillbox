#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <cstdlib>

int main() {
    std::cout << "Enter size pictures in pixel(width high):" << std::endl;
    int width, high;
    std::cin >> width >> high;
    while(width < 1 || high < 1){
        std::cout << "Input Incorrect! Enter again:";
        std::cin >> width >> high;
    }

    std::ofstream file;
    file.open("../pic.txt");
    if(!file.is_open()){
        std::cout << "Fail open file: " << std::strerror(errno) << std::endl;
        return errno;
    }

    std::srand(std::time(nullptr));

    for(int i = 0; i < high; i++){
       for(int j = 0; j < width; j++) file << std::rand()%2;
       file << std::endl;
    }

    file.close();
    return 0;
}
