#include <iostream>
#include <unordered_set>
#include <set>
#include <vector>
#include <memory>

int main() {

    auto foo = [](std::vector<int> &vec){
        std::unordered_set<int> set{};
        for(int & v : vec){
            if(set.contains(v)){
                std::cout << "element " << v <<" already contained" << std::endl;
            }
            set.insert(v);
        }
        vec.clear();

        for(auto &s : set)
            vec.push_back(s);

        std::unique_ptr<std::vector<int>> uPtr = std::make_unique<std::vector<int>>(vec);

        return uPtr;
    };

    std::vector<int> v = {1,3,4,2,5,1,4,9};
    for(auto &e : v)
        std::cout << e << " ";
    std::cout << std::endl;

    auto p = foo(v);

    for(auto e : *p)
        std::cout << e << " ";
    std::cout << std::endl;

    return 0;
}
