#include <iostream>

void init_shell(bool shell[12][12]){
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 12; j++)
            shell[i][j] = true;
}

int print_shell(bool shell[12][12]){
    int count_false = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(shell[i][j]) std::cout << "o ";
            else {
                std::cout << "x ";
                count_false++;
            }
        }
        std::cout << std::endl;
    }
    return count_false;
}

void pop_shell(bool shell[12][12],int x0, int y0, int x1, int y1){
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            if(shell[i][j]){
                shell[i][j] = false;
                std::cout << "Pop!" << std::endl;
            }
        }
    }
}

int main() {
    bool shell[12][12];
    int x0,y0,x1,y1;

    init_shell(shell);
    print_shell(shell);
    for(int end = 0; end < 144;){

        std::cout << "Enter start coordinates (row,col):";
        std::cin >> x0 >> y0;
        std::cout << "Enter end coordinates (row,col):";
        std::cin >> x1 >> y1;

        while(x0 < 0 || x0 >= 12 || y0 < 0 || y0 >= 12 ||
                x1 < 0 || x1 >= 12 || y1 < 0 || y1 >= 12){
            std::cout << "Coordinates incorrect! Enter again:" << std::endl;
            std::cout << "Enter start coordinates (row,col):";
            std::cin >> x0 >> y0;
            std::cout << "Enter end coordinates (row,col):";
            std::cin >> x1 >> y1;
        }

        if(x0 > x1) std::swap(x0,x1);
        if(y0 > y1) std::swap(y0,y1);

        pop_shell(shell,x0,y0,x1,y1);
        end = print_shell(shell);
    }
    return 0;
}
