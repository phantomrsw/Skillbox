#include <iostream>

int main() {
    std::cout << "Enter 15 integer numbers from a set of \n"
              << "14 consecutive numbers and one duplicate" << std::endl;
    int numbers[15];
    for(int i = 0; i < 15; i++){
        std::cout << "number " << i + 1 << ":";
        std::cin >> numbers[i];
        while(numbers[i] < 0){
            std::cout << "Error! Entered number negative! \n"
            <<"Enter again:";
            std::cin >> numbers[i];
        }
    }

    int sumNumbers = 0;
    int minNumber = numbers[0];

    int i = 0;
    for(const auto & elem : numbers){
        sumNumbers += numbers[i];
        if(numbers[i] < minNumber) minNumber = numbers[i];
        i++;
    }

    for(i = 0; i < 14; i++) sumNumbers -= minNumber + i;

    std::cout << "Repeating number: " << sumNumbers << std::endl;
    std::cout << "Asymptotic complexity of the algorithm is O(n). And it's less than O(n^2)." << std::endl;
    return 0;
}
