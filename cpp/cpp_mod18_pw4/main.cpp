#include <iostream>

void evendigits(long long n, int &ans){

    if((n%10)%2 == 0) ans++;
    n /= 10;
    if(n > 0) evendigits(n,ans);
    else return;
};


int main() {

    int ans;

    evendigits(9223372036854775806, ans);

    std::cout << ans;

    return 0;
}
