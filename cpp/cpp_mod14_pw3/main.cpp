#include <iostream>

void convert_to_diagonal_matrix(int m[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != j) m[i][j] = 0;
        }
    }
}

bool compare_matrix(int a[4][4], int b[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int a[4][4] = {{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    int b[4][4] = {{1,2,3,4},
                   {5,6,7,8},
                   {9,10,11,12},
                   {13,14,15,16}};
    std::cout << "Enter the elements of matrix A:" << std::endl;
    //for(int i = 0; i < 4; i++)
    for(const auto & i: {0,1,2,3}){
        for(int j = 0; j < 4; j++){
            std::cin >> a[i][j];
        }
    }
    std::cout << "Enter the elements of matrix B:" << std::endl;
    //for(int i = 0; i < 4; i++)
    for(const auto & i: {0,1,2,3}){
        for(int j = 0; j < 4; j++){
            std::cin >> b[i][j];
        }
    }
    if(!compare_matrix(a,b)){
        std::cout << "Matrix A and B not match! Exit from program." << std::endl;
        return 1;
    }
    else std::cout << "Matrix A and B match!" << std::endl;

    convert_to_diagonal_matrix(b);

    std::cout << "Matrix B converted to diagonal matrix:" << std::endl;

    for(const auto & i: {0,1,2,3}){
        for(int j = 0; j < 4; j++)
            std::cout << b[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}
