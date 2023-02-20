#include <iostream>
#include "main.h"

int main() {
    std::cout << std::string(20,'=') << std::endl;
    std::cout << "Operation Simulator" << std::endl;
    std::cout << std::string(20,'=') << std::endl;

    bool scalpelApplied = false;
    point_t a, scalpelStart, scalpelEnd, sutureStart, sutureEnd;
    std::string cmd;
    for(;;){
        std::cout << "Command:";
        std::cin >> cmd;

        if(cmd == "scalpel"){
            scalpelApplied = func_scalpel(&scalpelStart,&scalpelEnd);
        }
        else if(cmd == "hemostat" && scalpelApplied){
            func_hemostat(&a);
        }
        else if(cmd == "tweezers" && scalpelApplied){
            func_tweezers(&a);
        }
        else if(cmd == "suture" && scalpelApplied){
            func_suture(&sutureStart, &sutureEnd);
            if(compare_coordinate(&scalpelStart, &scalpelEnd, &sutureStart, &sutureEnd)){
                std::cout << "Operation complete success!";
                return 0;
            }
        }
        else{
            std::cout << "Incorrect command!" << std::endl;
        }

    }

}
