#pragma once
#include <iostream>

struct point_t{
    double x = 0.f;
    double y = 0.f;
};

bool func_scalpel(point_t* a, point_t* b){
    std::cout << "Enter the coordinates of the start of the cut(x y):";
    std::cin >> a->x >> a->y;
    std::cout << "Enter the coordinates of the end of the cut(x y):";
    std::cin >> b->x >> b->y;
    std::cout   << "The cut is made from point (" << a->x << "," << a->y
                << ") to point (" << b->x << "," << b->y << ")" << std::endl;
    return true;
}

void func_hemostat(point_t* a){
    std::cout << "Enter the coordinate of the hemostat installation point(x y):";
    std::cin >> a->x >> a->y;
    std::cout << "The hemostat is installed in (" << a->x << "," << a->y << ")" << std::endl;
}

void func_tweezers(point_t* a){
    std::cout << "Enter the coordinate to apply the tweezers (x y):";
    std::cin >> a->x >> a->y;
    std::cout << "The tweezers applied in (" << a->x << "," << a->y << ")" << std::endl;
}

void func_suture(point_t* a, point_t* b){
    std::cout << "Enter the coordinates of the start of the suture(x y):";
    std::cin >> a->x >> a->y;
    std::cout << "Enter the coordinates of the end of the suture(x y):";
    std::cin >> b->x >> b->y;
    std::cout   << "The suture is made from point (" << a->x << "," << a->y
                << ") to point (" << b->x << "," << b->y << ")" << std::endl;
}

bool compare_coordinate(point_t* a1, point_t* b1, point_t* a2, point_t* b2){
    if((a1->x == a2->x) && (a1->y == a2->y) &&
        (b1->x == b2->x) && (b1->y == b2->y)) return true;
    else return false;
}