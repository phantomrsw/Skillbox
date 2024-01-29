#include <iostream>
#include <ctime>

#define EMPTY 'O'
#define FISH 'F'
#define BOOT 'B'

#define SHOW_FIELD 0

class FishingSuccessException : public std::exception{
public:
    const char* what() const noexcept override{
        return "Fishing success! Yahoo!...You caught fish.";
    }
};

class FishingFailException : public std::exception{
public:
    const char* what() const noexcept override{
        return "Fishing fail! Oops...You caught the boot.";
    }
};

int main() {
    int attempts{};
    char field[9]={EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY};
    int sector{};

    std::cout << "Program FISHING" << std::endl;
    std::srand(std::time(nullptr));
    field[std::rand() % 9] = FISH;

    int i = 3;
    while(i){
        int pos = (std::rand() % 9);
        if(field[pos] == EMPTY){
            i--;
            field[pos] = BOOT;
        }
    }

#if SHOW_FIELD
    std::cout << std::string(6,'-') << "sectors" << std::string(6,'-') << std::endl;
    for(auto &e : field){
        printf(" %c", e);
    }
    std::cout << std::endl;
#endif

    try{
        for(;;){
            attempts++;
            std::cout << "Enter sector number:";
            std::cin >> sector;
            if(field[sector] == FISH){
                throw FishingSuccessException();
            }
            else if(field[sector] == BOOT){
                throw FishingFailException();
            }
            std::cout << "Empty!" << std::endl;
        }
    }
    catch (FishingSuccessException &ex){
        std::cout << ex.what() << std::endl;
        std::cout << "Number of attempts: " << attempts << std::endl;
    }
    catch(FishingFailException &ex){
        std::cout << ex.what() << std::endl;
        std::cout << "Number of attempts: " << attempts << std::endl;
    }

    return 0;
}
