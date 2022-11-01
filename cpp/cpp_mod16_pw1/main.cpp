#include <iostream>

bool compare(float value, float reference, float epsilon){
    return((value >= reference - epsilon)&&(value <= reference + epsilon));
}

int main() {
    float speed{},delta{};
    char buff[20];

    do{
        std::sprintf(buff, "%.1f", speed);
        std::cout << "Current speed:" << buff << std::endl;
        //std::cout << "Current speed(full):" << speed << std::endl;
        std::cout << "Enter delta speed:";
        std::cin >> delta;
        speed += delta;
        if(speed > 150.f) speed = 150.f;

    }while(!compare(speed,0.f,0.01f));

    return 0;
}
