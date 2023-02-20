#include <iostream>

#include "cpu.h"
#include "gpu.h"
#include "kbd.h"
#include "disk.h"

void display_help();

int main() {
    std::cout   << "=============================================\n"
                << " It is a computer emulation program \n"
                << "             Welcome!               \n"
                << " Build: " << __DATE__ << " " << __TIME__ << "\n"
                << " For display a list of commands, enter \"help\"\n"
                << "============================================="<< std::endl;

    std::string cmd;

    for(;;){
        std::cout << "\\>";
        std::cin >> cmd;

        if(cmd == "help"){
            display_help();
        }
        else if(cmd == "exit") {
            std::cout << "Program terminated. Goodbye" << std::endl;
            exit(0);
        }
        else if(cmd == "sum"){
            compute();
        }
        else if(cmd == "display"){
            display();
        }
        else if(cmd == "input"){
            input();
        }
        else if(cmd == "save"){
            if(!save()) std::cout << "RAM data success saved to disk!" << std::endl;
            else std::cout << "ERROR! Saving not complete!" << std::endl;
        }
        else if(cmd == "load"){
            if(!load()) std::cout << "Data success loaded to RAM from disk!" << std::endl;
            else std::cout << "ERROR! Loading data not be complete!" << std::endl;
        }
        else {
            std::cout << "Incorrect command!" << std::endl;
        }
    }
}

void display_help(){
    std::cout   << "List of available commands:\n"
                << "  - sum - calculate the sum\n"
                << "  - save - save to file\n"
                << "  - load - load from file\n"
                << "  - input - enter from the keyboard\n"
                << "  - display - display\n"
                << "  - exit - exits the program" << std::endl;
}