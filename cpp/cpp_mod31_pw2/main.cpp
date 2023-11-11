#include <iostream>
#include <memory>

#define DEBUG 0

class Toy{
    std::string name;
public:
    explicit Toy(const std::string &name) {
        this-> name = name;
#if DEBUG
        std::cout << "Constructor toy " << this->name << " " << this << std::endl;
#endif
    }
    std::string get_name() {
        return this->name;
    }
    ~Toy() {
#if DEBUG
        std::cout << "Destructor toy " << this->name << " " << this << std::endl;
#endif
    }
};

template<typename T>

class Shared_ptr{
    T *objPtr = nullptr;
    int count{};
    Shared_ptr* mainPtr = this;
public:

    Shared_ptr(T *ptr) : objPtr(ptr), count(1) {
#if DEBUG
        std::cout << "Constructor Shared_ptr " << this << "\n";
#endif
    }

    Shared_ptr() {
#if DEBUG
        std::cout << "Constructor Shared_ptr without args " << this << "\n";
#endif
    }

    ~Shared_ptr() {
        if(objPtr != nullptr && mainPtr->count == 1) {
            delete objPtr;
        }
        if(mainPtr->count > 0)
            mainPtr->count--;
#if DEBUG
        std::cout << "Destructor Shared_ptr " << this << "\n";
#endif
    }

    T& operator-> (){
        return *objPtr;
    };

    Shared_ptr(const Shared_ptr &copy){
        objPtr = copy.objPtr;
        mainPtr = copy.mainPtr;
        count = copy.mainPtr->count++;
#if DEBUG
        std::cout << "Copy constructor called " << this << "\n";
#endif
    }

    Shared_ptr& operator=(const Shared_ptr& other){
        objPtr = other.objPtr;
        mainPtr = other.mainPtr;
        count = other.mainPtr->count++;
#if DEBUG
        std::cout << "Operator= called " << this << "\n";
#endif
        return *this;
    }

    T* get(){return objPtr;}

    int use_count(){return mainPtr->count;}
};

Toy* make_shared_toy(const std::string &name){
    Toy* pt = new Toy(name);
    return pt;
}

int main() {

    /*Shared_ptr<Toy> ball = make_shared_toy("Ball");
    Shared_ptr<Toy> bone1 = ball;
    Shared_ptr<Toy> bone2(ball);;
    bone1 = bone2;
    std::cout << "Count = " << ball.use_count() << std::endl;
    std::cout << "Count = " << bone1.use_count() << std::endl;
    std::cout << "Count = " << ball.use_count() << std::endl;
    std::cout << "Count = " << bone2.use_count() << std::endl;*/

    {
        Shared_ptr<Toy> ball = make_shared_toy("Ball");
        Shared_ptr<Toy> bone1{ball};
        Shared_ptr<Toy> bone21 = bone1;
        Shared_ptr<Toy> bone22 = bone1;
        Shared_ptr<Toy> bone23 = bone1;
        std::cout << "count =  " << bone1.use_count() << std::endl;
    }
    {
        std::shared_ptr<int> pp1 = std::make_shared<int>(42);
        std::shared_ptr<int> pp2{pp1};
        std::shared_ptr<int> pp3 = pp2;
        std::shared_ptr<int> pp4 = pp2;
        std::shared_ptr<int> pp5 = pp2;
        std::cout << "count =  " << pp1.use_count() << std::endl;
    }
    return 0;
}
