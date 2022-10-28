#include <iostream>

int main() {

    int a[] = {-100,-50, -5, 1, 10, 15};

    int index = 0;
    for(;a[index] < 0; index++);

    for(int i = 0; i < index; i++){
        for (int j = 0; j < std::size(a) - 1 - i; j++){
            if(std::abs(a[j]) > std::abs(a[j + 1])) std::swap(a[j],a[j + 1]);
        }
    }

    for(auto e : a) std::cout << e << " ";
    return 0;
}
