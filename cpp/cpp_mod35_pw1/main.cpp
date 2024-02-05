#import <iostream>
#import <vector>

class A{
    std::vector<int> numbers;
public:
    A(std::initializer_list<int> list){
        numbers = list;
    }

    void print(){
        for(auto &n : numbers)
            std::cout << n << " ";
    }
};

int main() {
    A a({1,2,3,4,5});
    a.print();
    return 0;
}
