#include <iostream>

class Window{

    int x{0};
    int y{0};
    int width{10};
    int high{5};

public:

    void setX(int newX){x = newX;}

    void setY(int newY){y = newY;}

    void setWidth(int newWidth){width = newWidth;}

    void setHigh(int newHigh){high = newHigh;}

    int getX(){return x;}

    int getY(){return y;}

    int getWidth(){return width;}

    int getHigh(){return high;}
};

class Monitor{

    const int WIDTH = 80;
    const int HIGH = 50;

    Window window;

public:

    static std::string get_command(std::istream* cin){
        std::cout << "Enter command:";
        std::string s{};
        *(cin) >> s;
        return s;
    }

    void display(){
        for(int j{}; j < HIGH; j++){
            for(int i{}; i < WIDTH; i++){
                if((i >= window.getX() && i < (window.getX() + window.getWidth())) &&
                        (j >= window.getY() && j < (window.getY() + window.getHigh()))) std::cout << "1";
                else std::cout << "0";
                if(i == WIDTH - 1) std::cout << std::endl;
            }
        }
    }

    void resize(){
        std::cout << "Current width = " << window.getWidth() << " current high = " << window.getHigh() << std::endl;
        std::cout << "Enter new width an high (w h):";
        int w,h;
        std::cin >> w >> h;
        window.setWidth(std::abs(w));
        window.setHigh(std::abs(h));
        std::cout << "New width = " << window.getWidth() << " new high = " << window.getHigh() << std::endl;
    }

    void mov(){
        std::cout << "Current coordinates x = " << window.getX() << " y = " << window.getY() << std::endl;
        std::cout << "Enter new coordinate (x y):";
        int x{},y{};
        std::cin >> x >> y;
        window.setX(x % WIDTH);
        window.setY(y % HIGH);
        std::cout << "New coordinates x = " << window.getX() << " y = " << window.getY() << std::endl;
    }
};

int main() {
    std::cout << std::string(29,'=') << std::endl;
    std::cout << "Window control program" << std::endl;
    std::cout << std::string(29,'=') << std::endl;

    auto* pmonitor = new Monitor;


    std::string cmd;

    for(;;){

        cmd = Monitor::get_command(&std::cin);

        if(cmd == "close"){
            delete pmonitor;
            exit(0);
        }
        else if(cmd == "display"){
            pmonitor->display();
        }
        else if(cmd == "resize"){
            pmonitor->resize();
        }
        else if(cmd == "move"){
            pmonitor->mov();
        }
        else{
            std::cout << "Unknown command!" << std::endl;
        }
    }
}
