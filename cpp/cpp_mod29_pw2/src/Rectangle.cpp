#include "Rectangle.h"

Rectangle::Rectangle(double w, double h){
    width = w;
    height = h;
}

double Rectangle::square(){
    return width * width;
}

BoundingBoxDimensions Rectangle::dimensions(){
    BoundingBoxDimensions bbd;
    bbd.width = width + 0.1;
    bbd.height = height + 0.1;
    return bbd;
}

std::string Rectangle::type(){
    return typeName;
}
