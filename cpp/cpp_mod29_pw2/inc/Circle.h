#ifndef CPP_MOD29_PW2_CIRCLE_H
#define CPP_MOD29_PW2_CIRCLE_H

#pragma once

#include <iostream>
#include <cmath>
#include "Shape.h"

class Circle : public Shape{
    const std::string typeName = "Circle";
    double radius{};

public:

    explicit Circle(double r);

    double square() override;

    BoundingBoxDimensions dimensions() override;

    std::string type() override;

};


#endif //CPP_MOD29_PW2_CIRCLE_H
