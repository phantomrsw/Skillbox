#include "Circle.h"

    Circle::Circle(double r){
        radius = r;
    }

    double Circle::square(){
        return M_PI * std::pow(radius,2);
    }

    BoundingBoxDimensions Circle::dimensions(){
        BoundingBoxDimensions bbd;
        bbd.width = 2 * radius + 0.1;
        bbd.height = 2 * radius + 0.1;
        return bbd;
    }

    std::string Circle::type(){
        return typeName;
    }
