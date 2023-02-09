#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::cout << "================= Timer =================" << std::endl;

    std::time_t time{}, prevTime {}, valTimer{};
    std::tm local = *std::localtime(&time);

    std::cout << "Enter value timer (MM:SS):";
    std::cin >> std::get_time(&local,"%M:%S");

    valTimer = std::mktime(&local);
    prevTime = time = std::time(nullptr);

    while(valTimer){
        time = std::time(nullptr);
        if(time > prevTime){
            valTimer--;
            prevTime = time;
            std::cout << std::put_time(std::localtime(&valTimer),"%M:%S") << std::endl;
        }
    }

    std::cout << "DING! DING! DING!" << std::endl;
    return 0;
}
