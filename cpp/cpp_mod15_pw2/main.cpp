#include <iostream>

int main() {

    int a[] = {2, 7, 11, 15};
    int result = 13;

    for(int i = 0; i < std::size(a) - 1; i++){
        for(int j = i + 1; j < std::size(a); j++) {
            if(a[i] + a[j] == result) {
                std::cout << "First number = " << a[i] << "\nSecond number = " << a[j];
                return 0;
            }
        }
    }
    return 0;
}
