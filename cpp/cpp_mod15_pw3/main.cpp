#include <iostream>
#include <vector>

void bubble_sort(std::vector<int> &v){
    for (int i = (int)(v.size() - 1); i >= 0 ; i--)
        for(int j = 0; j < i; j++)
            if(v[j] > v[j + 1])
                std::swap(v[j],v[j+1]);
}

int main() {

    std::vector<int>array;

    std::cout << "Enter numbers:" << std::endl;
    int number = 0;
    while(number != -2){
        std::cin >> number;
        if(number == -1){
            if(array.size() < 4)
                std::cerr << "Fail! There are less than 5 elements in the array. Enter again:";
            else {
                bubble_sort(array);
                std::cout << "Output:" << array[4] << std::endl;
                std::cout << "Sorted array:{ ";
                for (int e : array) std::cout << e << " ";
                std::cout << "}" << std::endl;
            }
        }
        else array.push_back(number);
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
