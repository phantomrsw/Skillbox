#include <iostream>

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};

    int sum = a[0] + a[1];
    int index1 = 0, index2 = 1;

    for(int i = 0; i < std::size(a) - 1; i++){
        for(int j = i + 1; j < std::size(a); j++){
            int temp = 0;
            for(int k = i; k <= j; k++) temp += a[k];
            if(temp > sum){
                sum = temp;
                index1 = i;
                index2 = j;
            }
        }
    }

    std::cout << "First index = " << index1
              << "\nSecond index = " << index2
              << "\nSum = " << sum
              << std::endl;
    return 0;
}
