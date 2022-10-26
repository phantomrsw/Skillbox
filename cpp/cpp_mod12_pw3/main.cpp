#include <iostream>
#include <cassert>

float travelTime(float distance, float speed){
    assert(speed > 0);
    return distance / speed;
}

int main() {
    float distance,speed;
    std::cout << "Enter distance:";
    std::cin >> distance;
    std::cout << "Enter speed:";
    std::cin >> speed;

    std::cout << "Travel time: " << travelTime(distance,speed);

    return 0;
}
