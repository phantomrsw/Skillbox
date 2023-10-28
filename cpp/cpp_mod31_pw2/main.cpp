#include <iostream>

class Toy{
    std::string name;
public:
    explicit Toy(const std::string &name) {
        this-> name = name;
        std::cout << "Constructor toy " << this->name << " " << this << std::endl;
    }
    std::string get_name() {
        return this->name;
    }
    ~Toy() {
        std::cout << "Destructor toy " << this->name << " " << this << std::endl;
    }
};

template<typename T>

class Shared_ptr_toy{
    T *ptr = nullptr;
    int count{};
public:

    Shared_ptr_toy(T *ptr) : ptr(ptr), count(0) {
        std::cout << "Constructor Shared_ptr " << this << "\n";
    }

    Shared_ptr_toy() {
        ptr = new T("Unknown");
        std::cout << "Constructor Shared_ptr Unknown" << this << "\n";
    }


    ~Shared_ptr_toy() {
        if(ptr != nullptr && count == 0) delete ptr;
        else count--;
        std::cout << "Destructor Shared_ptr " << this << "\n";
    }

    T& operator-> (){
        return *ptr;
    };

    Shared_ptr_toy(const Shared_ptr_toy &copy){
        ptr = copy.ptr;
        count++;
        std::cout << "Copy constructor called " << this << "\n";
    }

    Shared_ptr_toy& operator= (const Shared_ptr_toy& other){
        ptr = other.ptr;
        count++;
        std::cout << "Operator= called " << this << "\n";
        return *this;
    }

    T* get(){return ptr;}

    int use_count(){return count;}
};

Toy* make_shared_toy(const std::string &name){
    Toy* pt = new Toy(name);
    return pt;
}

int main() {

    Shared_ptr_toy<Toy> ball = make_shared_toy("Ball");

    Shared_ptr_toy<Toy> bone1;
    Shared_ptr_toy<Toy> bone2(ball);;
    bone1 = bone2;

    return 0;
}
