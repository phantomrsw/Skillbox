#include <iostream>

int main() {
    std::string residents[10];
    std::cout << "Enter 10 last names of apartment residents." <<std::endl;
    for(int i = 0; i < 10; i++){
        std::cout << "appart. " << i+1 << ": " << std::endl;
        std::cin >> residents[i];
    }
    for(int i = 0; i < 3; i++){
        std::cout << "Enter apartment number:" << std::endl;
        int n;
        std::cin >> n;
        while(n < 1 || n > 10){
            std::cout << "Input is invalid! Enter again:" << std::endl;
            std::cin >> n;
        }
        std::cout << "The apartment is reside:" << residents[n - 1] << std::endl;
    }

    return 0;
}
