#include <iostream>

template < typename T >
void input(T array[8]){
    std::cout << "Fill the array (8):";
    for (int i = 0; i < 8; ++i)
    {
        std::cin >> array[i];
    }
}

template <typename T>
T calc(T array[8]){
    T result{};
    for(int i = 0; i < 8; i++){
        result += array[i];
    }
    return result / 8;
}

int main() {
    float a[8];
    input(&a[0]);
    std::cout << "Result=" << calc(&a[0]) << std::endl;
    return 0;
}
