#include <iostream>
#include <vector>

#define MEM_SIZE 20

int main() {
    std::vector<int> db(MEM_SIZE);
    int pointerWrite = 0, pointerRead = 0;
    int countNumbers = 0;
    int number;

    for(;;){
        std::cout << "Enter number:";
        std::cin >> number;

        if(number == -1){
            for(const auto & e : db){
                std::cout << db[pointerRead++] << " ";
                if(pointerRead == MEM_SIZE) pointerRead = 0;
            }
            std::cout << std::endl;
        }
        else if(number == -2){
            std::cout << "The program has ended." << std::endl;
            break;
        }
        else{
            db[pointerWrite++] = number;
            if(pointerWrite == MEM_SIZE) pointerWrite = 0;

            if(countNumbers < MEM_SIZE) {
                countNumbers++;
                pointerRead = 0;
            }
            else{/*countNumbers == MEM_SIZE*/
                if(pointerRead < MEM_SIZE) pointerRead = pointerWrite;
                else pointerRead = 0;
            }
        }
    }
    return 0;
}
