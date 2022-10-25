#include <iostream>

int main() {
    float a[4][4] = {{1.f, 1.f, 1.f, 1.f},
                     {1.f, 1.f, 1.f, 1.f},
                     {1.f, 1.f, 1.f, 1.f},
                     {1.f, 1.f, 1.f, 1.f}};
    float b[4] = {1.f, 2.f, 3.f, 4.f};
    float c[4];

    std::cout << "Enter the elements of matrix A[4][4]:" << std::endl;
    for (const auto &i: {0, 1, 2, 3}) {
        for (int j = 0; j < 4; j++) {
            std::cin >> a[i][j];
        }
    }
    std::cout << "Enter the elements of vector B[4]:" << std::endl;
    for (const auto &i: {0, 1, 2, 3}) {
        std::cin >> b[i];
    }

    for (int i = 0; i < 4; i++) {
        float acc = 0;
        for (int j = 0; j < 4; j++) {
            acc += a[i][j] * b[j];
        }
        c[i] = acc;
    }

    std::cout << "Vector c[4] is:" << std::endl;
    for (const auto & i : {0, 1, 2, 3}) {
        std::cout << c[i] << " ";
    }

    return 0;
}
