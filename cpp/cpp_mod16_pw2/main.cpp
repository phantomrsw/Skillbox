#include <iostream>

int main() {

    std::cout << "Enter integer part of number:";
    std::string i;
    std::cin >> i;
    std::cout << "Enter fractional part of number:";
    std::string f;
    std::cin >> f;

    std::cout << "Result:" << std::stod((i + '.' + f));
    return 0;
}
