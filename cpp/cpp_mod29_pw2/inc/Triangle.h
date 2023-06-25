#ifndef CPP_MOD29_PW2_TRIANGLE_H
#define CPP_MOD29_PW2_TRIANGLE_H

#pragma once

#include <iostream>
#include <cmath>
#include "Shape.h"

class Triangle : public Shape{
    const std::string typeName = "Triangle";
    double a{}, b{}, c{};

public:

    explicit Triangle(double _a, double _b, double _c);

    double square() override;

    BoundingBoxDimensions dimensions() override;

    std::string type() override;

};

#endif //CPP_MOD29_PW2_TRIANGLE_H
