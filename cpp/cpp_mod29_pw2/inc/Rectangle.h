#ifndef CPP_MOD29_PW2_RECTANGLE_H
#define CPP_MOD29_PW2_RECTANGLE_H

#pragma once

#include <iostream>
#include <cmath>
#include "Shape.h"

class Rectangle : public Shape{
    const std::string typeName = "Rectangle";
    double width{}, height{};

public:

    explicit Rectangle(double w, double h);

    double square() override;

    BoundingBoxDimensions dimensions() override;

    std::string type() override;

};

#endif //CPP_MOD29_PW2_RECTANGLE_H
