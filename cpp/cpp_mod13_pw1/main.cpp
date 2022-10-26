#include <iostream>
#include <vector>

int main() {
    std::cout << "Enter size of vector:";
    int n;
    std::cin >> n;
    while(n <= 0){
        std::cout << "Fail input! Enter again:";
        std::cin >> n;
    }

    std::vector<int>vec(n);

    n = 0;
    std::cout << "Enter the number for element of vector:" << std::endl;
    for(const auto & e : vec) {
        std:: cin >> vec[n++];
    }

    std::cout << "Enter number to delete:";
    int del;
    std::cin >> del;

    for(int i = 0; i < vec.size(); i++){
        while(vec[i] == del){
            for(int j = i; j < vec.size() - 1; j++){
                vec[j] = vec[j+1];
            }
            vec.pop_back();
        }
    }

    std::cout << "Result: ";
    n = 0;
    for(const auto & e: vec){
        std::cout << vec[n++] << " ";
    }

    return 0;
}
