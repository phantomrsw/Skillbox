#include <iostream>

#define NUM_COMB 12

int main() {

    std::string combinations[NUM_COMB];

    enum note
    {
        DO = 1,
        RE = 2,
        MI = 4,
        FA = 8,
        SOL = 16,
        LA = 32,
        SI = 64
    };

    //note notes;

    std::cout << "Enter note combination:" << std::endl;
    int i = 0;
    for (auto &c: combinations){
        std::cout << "[" << i + 1 << "]:";
        std::cin >> combinations[i++];
    }

    std::cout << "Melody: ";

    for(i = 0; i < NUM_COMB; i++){
        int j = 0;
        for(auto & c : combinations[i])
        {
            int n = (combinations[i][j++] - '0' - 1);
            if(DO & (1 << n)) std::cout << "DO ";
            else if(RE & (1 << n)) std::cout << "RE ";
            else if(MI & (1 << n)) std::cout << "MI ";
            else if(FA & (1 << n)) std::cout << "FA ";
            else if(SOL & (1 << n)) std::cout << "SOL ";
            else if(LA & (1 << n)) std::cout << "LA ";
            else if(SI & (1 << n)) std::cout << "SI ";
        }
        std::cout << "  ";
    }

    return 0;
}
