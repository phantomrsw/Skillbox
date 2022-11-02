#include <iostream>

void swap_a(int* a) {
    for (int i = 0; i < 5; i++) {
        std::swap(*(a + i), *(a + 9 - i));
    }
}
int main() {
    int a[10] = {0,1,2,3,4,5,6,7,8,9};
    swap_a(a);
    for(auto i : a) std::cout << i << " ";
}
