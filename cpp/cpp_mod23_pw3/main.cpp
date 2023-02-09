#include <iostream>

#define MAX_PASSENGERS 20
#define MAX_WAGONS 10

#define GET_PASSENGERS(a,b) std::cout << b(a)
#define GET_WAGONS(a,b) for(int i = 0; i < MAX_WAGONS; i++) if(b(a[i]))std::cout << a[i] << " "

int total(int t[]) {
    int n = 0;
    for(int i = 0; i < MAX_WAGONS; i++) n += t[i];
    return n;
}

bool greated(int i) {return i > MAX_PASSENGERS;}
bool less(int i) {return i < MAX_PASSENGERS;}


int main() {

    int train [MAX_WAGONS] = {1,21,3,41,5,61,7,81,9,10};

    std::cout << "\nNumbers of overcrowded wagons:";
    GET_WAGONS(train,greated);

    std::cout << "\nNumbers of wagons with empty seats:";
    GET_WAGONS(train,less);

    std::cout << "\nTotal passengers:";
    GET_PASSENGERS(train,total);
}
