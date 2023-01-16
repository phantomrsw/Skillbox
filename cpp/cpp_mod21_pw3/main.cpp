/*This task is solved for the case when the origins
 * of all vectors coincide with the origin coordinates*/

#include <iostream>
#include <vector>
#include <cmath>

const std::string operationList[]={
        "add",
        "subtract",
        "scale",
        "length",
        "normalize"
};

struct xy_vec_t{
    float x = 0.f;
    float y = 0.f;
};

int check_operation(std::string* op, const std::string* opList, int opListSize){
    for(int i = 0; i < opListSize; i++) {
        if(*op == *(opList + i)) return 0;
    }
   return 1;
}

void add_vectors(){
    xy_vec_t a, b;
    std::cout << "Enter vector A coordinates:";
    std::cin >> a.x >> a.y;
    std::cout << "Enter vector B coordinates:";
    std::cin >> b.x >> b.y;
    std::cout   << "Vector C (equal to the sum A + B) has coordinates: ("
                << a.x + b.x << ", " << a.y + b.y << ")";
}

void substract_vectors(){
    xy_vec_t a, b;
    std::cout << "Enter vector A coordinates:";
    std::cin >> a.x >> a.y;
    std::cout << "Enter vector B coordinates:";
    std::cin >> b.x >> b.y;
    std::cout   << "Vector C (equal to the difference A - B) has coordinates: ("
                << a.x - b.x << ", " << a.y - b.y << ")";
}

void multipl_vector_by_scalar(){
    xy_vec_t a;
    std::cout << "Enter vector coordinates:";
    std::cin >> a.x >> a.y;
    float n;
    std::cout << "Enter number to multiply:";
    std::cin >> n;
    std::cout << "New vector coordinates: (" << a.x * n << ", " << a.y * n << ")";
}

void get_vector_length(){
    xy_vec_t a;
    std::cout << "Enter vector coordinates:";
    std::cin >> a.x >> a.y;
    std::cout << "Vector length = " << (std::sqrt(std::pow(a.x,2) + std::pow(a.y,2)));
}

void normalize_vector(){
    xy_vec_t a;
    std::cout << "Enter vector coordinates:";
    std::cin >> a.x >> a.y;
    std::cout   << "New coordinates of the normalized vector:"
                << a.x/(std::sqrt(std::pow(a.x,2) + std::pow(a.y,2))) << ", "
                << a.y/(std::sqrt(std::pow(a.x,2) + std::pow(a.y,2)));
}

void (*funcList[])()={
    add_vectors,
    substract_vectors,
    multipl_vector_by_scalar,
    get_vector_length,
    normalize_vector
};

int main() {

    std::cout << "List available operation: " << std::endl;
    for(auto & c : operationList) std::cout << "\t- " << c << std::endl;

    std::string operation;
    std::cout << "Enter operation:";
    std::cin >> operation;
    while (check_operation(&operation, &operationList[0], std::size(operationList))){
        std::cout << "Incorrect input! Enter again:";
        std::cin >> operation;
    }

    for(int i = 0; i < std::size(operationList); i++){
        if(operation == operationList[i]) funcList[i]();
    }

    return 0;
}
