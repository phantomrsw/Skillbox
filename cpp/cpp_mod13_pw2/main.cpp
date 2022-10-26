#include <iostream>
#include <vector>

int main() {
    std::vector<float> prices {2.5, 4.25, 3.0, 10.0};
    std::vector<int> items {1, 1, 0, 3};
    float totalCost = 0.f;

    int i = 0;
    for(const auto & e : items){
        if(items[i] < 0 || items[i] > prices.size() - 1)
        {
            std::cout << "Fail! The Items vector cannot \n"
                         "contain a value < 0 or value > " << prices.size() - 1;
            return 0;
        }
        i++;
    }

    i = 0;
    for(const auto & e : items){
        totalCost += prices[items[i++]];
    }

    std::cout << "Total cost: " << totalCost << std::endl;
    return 0;
}
