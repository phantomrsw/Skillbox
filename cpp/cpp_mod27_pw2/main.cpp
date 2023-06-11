#include <iostream>
#include <cmath>

enum color_t{NONE, RED, BLUE, GREEN};

class figure{
    double x{},y{};
    color_t color = NONE;

public:

    void set_color(){
        std::cout << "Enter figure color:";
        std::string c;
        std::cin >> c;
        if(c == "red") color = RED;
        else if(c == "blue") color = BLUE;
        else if(c == "green") color = GREEN;
        else std::cout << "Unknown color";
    }

    std::string get_color(){
        return color == RED ? "RED" : (color == BLUE ? "BLUE" : (color == GREEN ? "GREEN" : "NONE"));
    }

    void set_coordinate(){
        std::cout << "Enter the coordinates of this figure(x y):";
        std::cin >> x >> y;
    }

    double get_x(){return x;}
    double get_y(){return y;}

};

class Circle : public figure{
    double radius{};

public:

    Circle(){
        std::cout << "Enter radius of circle:";
        std::cin >> radius;
        set_color();
        set_coordinate();
    };

    double get_area(){
        return atan(1) * 4 * radius;
    }

    void show_outside_rectangle_coordinates(){
        std::cout   << "Coordinates of outside rectangle:"
                    << "(" << get_x() - (radius + 0.1) << "," << get_y() - (radius + 0.1) << ") "
                    << "(" << get_x() - (radius + 0.1) << "," << get_y() + (radius + 0.1) << ") "
                    << "(" << get_x() + (radius + 0.1) << "," << get_y() + (radius + 0.1) << ") "
                    << "(" << get_x() + (radius + 0.1) << "," << get_y() - (radius + 0.1) << ") ";
    }

};

class Square : public figure{
    double length{};

public:

    Square(){
        std::cout << "Enter length side of square:";
        std::cin >> length;
        set_color();
        set_coordinate();
    }

    double get_area(){
        return length*length;
    }

    void show_outside_rectangle_coordinates(){
        std::cout   << "Coordinates of outside rectangle:"
                    << "(" << get_x() - (length/2 + 0.1) << "," << get_y() - (length/2 + 0.1) << ") "
                    << "(" << get_x() - (length/2 + 0.1) << "," << get_y() + (length/2 + 0.1) << ") "
                    << "(" << get_x() + (length/2 + 0.1) << "," << get_y() + (length/2 + 0.1) << ") "
                    << "(" << get_x() + (length/2 + 0.1) << "," << get_y() - (length/2 + 0.1) << ") ";
    }
};

class Triangle : public figure{
    double length{};

public:

    Triangle(){
        std::cout << "Enter length side of triangle:";
        std::cin >> length;
        set_color();
        set_coordinate();
    }

    double get_area(){
        return length * length * std::sqrt(3) / 4;
    }

    void show_outside_rectangle_coordinates(){
        std::cout   << "Coordinates of outside rectangle:"
                    << "(" << get_x() - (length/2 + 0.1) << "," << get_y() - ((length/2)/std::sqrt(3) + 0.1) << ") "
                    << "(" << get_x() - (length/2 + 0.1) << "," << get_y() + (length/std::sqrt(3) + 0.1) << ") "
                    << "(" << get_x() + (length/2 + 0.1) << "," << get_y() + (length/std::sqrt(3) + 0.1) << ") "
                    << "(" << get_x() + (length/2 + 0.1) << "," << get_y() - ((length/2)/std::sqrt(3) + 0.1) << ") ";
    }
};

class Rectangle : public figure{
    double high{};
    double width{};

public:

    Rectangle(){
        std::cout << "Enter high and width of rectangle:";
        std::cin >> high >> width;
        set_color();
        set_coordinate();
    }

    double get_area(){
        return high * width;
    }

    void show_outside_rectangle_coordinates(){
        std::cout   << "Coordinates of outside rectangle:"
                    << "(" << get_x() - (width/2 + 0.1) << "," << get_y() - (high/2 + 0.1) << ") "
                    << "(" << get_x() - (width/2 + 0.1) << "," << get_y() + (high/2 + 0.1) << ") "
                    << "(" << get_x() + (width/2 + 0.1) << "," << get_y() + (high/2 + 0.1) << ") "
                    << "(" << get_x() + (width/2 + 0.1) << "," << get_y() - (high/2 + 0.1) << ") ";
    }
};

int main() {
    std::cout << "Your command(circle, square, triangle, rectangle):";
    std::string cmd;
    std::cin >> cmd;
    if(cmd == "circle"){
        Circle* circle = new Circle;
        std::cout << "Color=" << circle->get_color() << ", Area=" << circle->get_area() << std::endl;
        circle->show_outside_rectangle_coordinates();
        delete circle;
    }
    else if(cmd == "square"){
        Square* square = new Square;
        std::cout << "Color=" << square->get_color() << ", Area=" << square->get_area() << std::endl;
        square->show_outside_rectangle_coordinates();
        delete square;
    }
    else if(cmd == "triangle"){
        Triangle* triangle = new Triangle;
        std::cout << "Color=" << triangle->get_color() << ", Area=" << triangle->get_area() << std::endl;
        triangle->show_outside_rectangle_coordinates();
        delete triangle;
    }
    else if(cmd == "rectangle"){
        Rectangle* rectangle = new Rectangle;
        std::cout << "Color=" << rectangle->get_color() << ", Area=" << rectangle->get_area() << std::endl;
        rectangle->show_outside_rectangle_coordinates();
        delete rectangle;
    }
    else{
        std::cout << "Unknown command";
    }

    return 0;
}
