#include <iostream>
#include <memory>

class Toy{
    std::string name;
public:
    Toy(const std::string &name) {
        this-> name = name;
    }
    std::string get_name() {
        return this->name;
    }
    ~Toy() {
        std::cout << "Toy " << this->name << " was dropped " << std::endl;
    }
};

class Dog{
    std::string name;
    std::shared_ptr<Toy> pToy{nullptr};
public:
    explicit Dog(const std::string &name){
        this->name = name;
    }

    ~Dog() {
        std::cout << name << " is dead..." << std::endl;
    }

    void get_toy(std::shared_ptr<Toy> &ptr){
        if(ptr == pToy)
            std::cout << "I already have this toy." << std::endl;
        else if(ptr.use_count() == 2)
            std::cout << "Another dog is playing with this toy." << std::endl;
        else{
            pToy = ptr;
            std::cout << "I picked up a toy." << std::endl;
        }
    }

    void drop_toy(){
        if(this->pToy == nullptr)
            std::cout << "Nothing to drop." << std::endl;
        else{
            this->pToy = nullptr;
            std::cout << "I dropped the toy." << std::endl;
        }
    }
};

int main() {

    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");

    Dog a("Barbos"),b("Sharik");

    a.drop_toy();
    a.get_toy(ball);
    a.get_toy(ball);
    b.get_toy(ball);
    a.drop_toy();

    return 0;
}
