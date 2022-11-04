#include <iostream>

int func(int n){
    int count = 0;
    if(n > 0 && n <= 3) count = (1 << (n - 1));
        /*else if(n == 2) count +=  2;
        else if(n == 3) count +=  4;*/
    else if(n > 3){
        n--;
        count += func(n) * 2 -1;
    }

    return count;
}

int main()
{
    std::cout << "How many steps must the rabbit jump:";
    int n = 5;
    std::cin >> n;
    if(n < 0) n = -n;

    std::cout << "Number of possible combinations:" << func(n);
    return 0;
}
