#include <iostream>
#include <sstream>

bool check_input(std::string &a,std::string &op, std::string &b){
    if((op != "+" && op != "-" && op != "*" && op != "/")) {
        std::cout << "Operation incorrect. Enter again:" << std::endl;
        return false;
    }
    return true;
}

double calculation(std::string &a,std::string &op, std::string &b){
    if(op == "+") return std::stod(a) + std::stod(b);
    else if(op == "-") return std::stod(a) - std::stod(b);
    else if(op == "*") return std::stod(a) * std::stod(b);
    else if(op == "/") return std::stod(a) / std::stod(b);
    return 0.f;
}

int main() {

    std::string buffer, a, op, b;

    do {
        std::cout << "Enter action:";
        std::getline(std::cin, buffer);
        std::stringstream bufferStream(buffer);
        bufferStream >> a >> op >> b;
    }while(!check_input(a, op, b));

    //std::cout << "a = " << a <<" op = " << op << " b = " << b << std::endl;

    std::cout  << "Result:" << calculation(a, op, b);
    return 0;
}
