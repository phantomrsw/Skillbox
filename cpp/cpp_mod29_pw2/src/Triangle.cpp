#include "Triangle.h"

Triangle::Triangle(double _a, double _b, double _c){
    a = _a;
    b = _b;
    c = _c;
}

double Triangle::square(){
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

BoundingBoxDimensions Triangle::dimensions(){
    double p = (a + b + c) / 2;
    double r = a * b * c / (4 * sqrt(p*(p - a)*(p - b)*(p - c)));
    BoundingBoxDimensions bbd;
    bbd.width = r * 2 + 0.1;
    bbd.height = r * 2 + 0.1;
    return bbd;
}

std::string Triangle::type(){
    return typeName;
}