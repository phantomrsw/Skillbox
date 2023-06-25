#include <iostream>
#include <vector>

#define DEBUG false

static void debug_show(const std::string &s){
#if DEBUG == true
    std::cout << s << std::endl;
#endif
}

class Talent{

public:

    Talent() = default;
    virtual ~Talent() = 0;

    virtual std::string show() = 0;
};

Talent::~Talent()= default;

class Swimming : public Talent{

public:

    Swimming(){
        debug_show("Constructor Swimming");
    }

    ~Swimming () override{
        debug_show("Destructor Swimming");
    }

    std::string show() override{
        return "swim";
    }
};

class Dancing : public Talent{

public:

    Dancing(){
        debug_show("Constructor Dancing");
    }

    ~Dancing() override{
        debug_show("Destructor Dancing");
    }

    std::string show() override{
        return "dance";
    }
};

class Counting : public Talent{

public:

    Counting(){
        debug_show("Constructor Counting");
    }

    ~Counting() override{
        debug_show("Destructor Counting");
    }

    std::string show()override{
        return "count";
    }
};

class Dog{

    std::string name;
    std::vector<Talent *> d;

public:

    explicit Dog(const std::string& name){
        this->name = name;
        std::cout   << "Talents are available for the " << name << " dog:\n"
                    << " 1 - swim\n"
                    << " 2 - dance\n"
                    << " 3 - count\n"
                    << "Enter numbers of talents or \'0\' for input ending" << std::endl;

        int cnt{},t{}, choiceNumbers[3]{-1,-1,-1};
        Talent *tptr;

        while(cnt < 3){
            std::cout << "Enter number talent:";
            std::cin >> t;
            for(auto i : choiceNumbers){
                if(t == i){
                    std::cout << "Such talent already exists." << std::endl;
                    t = -1;
                }
            }

            choiceNumbers[cnt] = t;

            if(t == 1){
                tptr = new Swimming;
                d.push_back(tptr);
                cnt++;
            }
            else if(t == 2){
                tptr = new Dancing;
                d.push_back(tptr);
                cnt++;
            }
            else if(t == 3){
                tptr = new Counting;
                d.push_back(tptr);
                cnt++;
            }
            else if(t == 0){
                break;
            }
            else{
                std::cout << "Input incorrect!" << std::endl;
            }
        }
    }

    ~Dog(){
        for(auto  i : d)
            delete i;
    }

    void show_talents(){
        std::cout << "Dog " << name << " can:" << std::endl;
        for(auto & i : d)
            std::cout << " - " << i->show() << std::endl;
    }
};

int main() {

    Dog dog("Steve");

    dog.show_talents();

    return 0;
}
