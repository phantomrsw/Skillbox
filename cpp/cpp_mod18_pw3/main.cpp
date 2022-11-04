#include <iostream>

int func(int n, int k = 3){
    int count = 0;
    if(n > 0 && n <= k) count = (1 << (n - 1));
    else if(n > k){
        n--;
        count += func(n) * 2 -1;
    }
    return count;
}

int main()
{
    std::cout << "Enter the number of steps and the largest jump for the rabbit (n k):";
    int n, k;
    std::cin >> n >> k;
    if(n < 0) n = -n;
    if(k < 0) k = -k;

    std::cout << "Number of possible combinations:" << func(n,k);
    return 0;
}
