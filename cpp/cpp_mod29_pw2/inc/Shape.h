#ifndef CPP_MOD29_PW2_SHAPE_H
#define CPP_MOD29_PW2_SHAPE_H
#pragma once

#include <iostream>

struct BoundingBoxDimensions{
    double width{};
    double height{};
};

class Shape{

public:

    Shape() = default;

    virtual double square() = 0;
    virtual BoundingBoxDimensions dimensions() = 0;
    virtual std::string type() = 0;

};

#endif //CPP_MOD29_PW2_SHAPE_H
