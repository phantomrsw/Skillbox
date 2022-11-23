#include <iostream>
#include <fstream>

int load_atmState(std::string &path, int* dest, int destLength){
    std::ifstream iatmState;
    iatmState.open(path,std::ios::binary);
    if(!iatmState.is_open()){
        return errno;
    }
    else{
        for(int i = 0; i < destLength; i++) iatmState >> *(dest + i);
    }
    iatmState.close();
    return 0;
}

int save_atmState(std::string &path, int* dest, int destLength){
    std::ofstream oatmState;
    oatmState.open(path,std::ios::binary);
    if(!oatmState.is_open()){
        return errno;
    }
    else{
        for(int i = 0; i < destLength; i++) oatmState << *(dest + i) << " ";
    }
    oatmState.close();
    return 0;
}

int main() {
    int banknotes[] = {100,200,500,1000,2000,5000};
    int countBanknotes[sizeof(banknotes)/4]{};
    int totalCache = 0;
    std::string path = "../atmState.bin";

    std::cout << "Enter action ('+' or '-'):" << std::endl;
    std::string action;
    std::cin >> action;

    while(action != "+" && action != "-") {
        std::cout << "Incorrect input! Enter again:";
        std::cin >> action;
    }

    if(action == "+"){

        load_atmState(path, countBanknotes, std::size(countBanknotes));

        int totalBanknotes = 0;
        for(int & v : countBanknotes) totalBanknotes += v;

        for(int i = totalBanknotes; i < 1000; i++){
            int index = std::rand()%std::size(banknotes);
            countBanknotes[index] ++;
        }

        save_atmState(path, countBanknotes, std::size(countBanknotes));
    }
    else{
        std::cout << "Enter amount to withdraw:";
        int cache;
        std::cin >> cache;
        while(cache%100){
            std::cout << "Incorrect input! Sum must be a multiple of 100. Enter again:";
            std::cin >> cache;
        }

        load_atmState(path, countBanknotes, std::size(countBanknotes));

        for(int i = 0; i < std::size(banknotes); i++) totalCache += banknotes[i] * countBanknotes[i];

        if(totalCache < cache) {
            std::cout << "There is not enough money in the ATM!" << std::endl;
            return 0;
        }
        else {
            for(int i = std::size(banknotes); cache > 0;) {
                if (cache >= banknotes[i] && countBanknotes[i] > 0) {
                    cache -= banknotes[i];
                    countBanknotes[i]--;
                } else i--;
            }
            save_atmState(path, countBanknotes, std::size(countBanknotes));
        }
    }
    return 0;
}
