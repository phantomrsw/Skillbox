#include <iostream>
#include <map>
#include <iomanip>
#include <utility>
#include <vector>
#include <exception>

#define DEBUG 0

class Container{

protected:
    std::map<std::string,int> list;
    std::string type = "Container";

public:

    explicit Container(std::string _t):type(std::move(_t)){
#if DEBUG
        std::cout << "Constructor " << type << " this=" << this << std::endl;
#endif
    };

#if DEBUG
    ~Container(){
        std::cout << "Destructor " << type << " this=" << this << std::endl;
    }
#else
    ~Container()= default;
#endif

    void print(){
        std::cout << std::string(8,'-') << type << std::string(9,'-') << std::endl;
        std::cout << std::left  << std::setw(10) << "articles" << ":"
                  << std::right << std::setw(10) << "quantity" << std::endl;
        std::cout << std::string(21,'-') << std::endl;
        for(auto & it : list){
            std::cout << std::left  << std::setw(10) << it.first << ":"
                      << std::right << std::setw(10) << it.second << std::endl;
        }
    }

    void add(std::string& articles, int quantity){
        if(list.contains(articles)){
            list[articles] += quantity;
        }
        else{
            list.insert(std::make_pair(articles,quantity));
        }
    }

    void remove(std::string &article, int quantity){
        if(!list.contains(article))
            throw std::runtime_error("article \"" + article + "\"" + " not in cart");
        if(list[article] < quantity)
            throw std::runtime_error("no required quantity in cart");

        list[article] -= quantity;

        if(list[article] == 0)
            list.erase(article);
    }
};

class Cart : public Container{
public:
    explicit Cart(std::string _t) : Container(std::move(_t)){};
};

class Stock : public Container{
public:
    explicit Stock(std::string _t) : Container(std::move(_t)){};
};

class Shop{
    Stock* pStock{nullptr};
    Cart* pCart{nullptr};
    enum cart_op_t {CART_ADD,CART_REMOVE};
public:
    Shop() {
#if DEBUG
        std::cout << "Constructor Shop " << this << std::endl;
#endif
        pStock = new Stock((std::string)"Stock");
        pCart = new Cart((std::string)"Cart");
    }

    ~Shop(){
#if DEBUG
        std::cout << "Destructor Shop " << this << std::endl;
#endif
        if(pStock != nullptr){
            delete pStock;
            pStock = nullptr;
        }
        if(pCart != nullptr){
            delete pCart;
            pCart = nullptr;
        }
    }

private:

    void print_stock(){
        if(pStock != nullptr)
            pStock->print();
    }

    void print_cart(){
        if(pCart != nullptr)
            pCart->print();
    }

    void add_to_stock(){
        std::string article;
        int quantity;
        bool action_success = false;
        bool input_success = false;

        while(!action_success) {
            try {
                input(article, quantity);
                input_success = true;
            }
            catch (std::invalid_argument &ex) {
                std::cerr << "Exception Input:" << ex.what() << std::endl;
            }
            if(input_success) {
                if (pStock != nullptr)
                    pStock->add(article, quantity);
                action_success = true;
            }
        }
    }

    static void input(std::string &article, int &quantity){
        std::string s;

        std::cout << "Enter articles:";
        std::cin >> s;
        if(s.length() != 2){
            throw std::invalid_argument("length article != 2") ;
        }
        article = s;

        std::cout << "Enter quantity:";
        std::cin >> s;
        for(auto &c : s){
            if(!isdigit(c)){
                throw std::invalid_argument("quantity not digit");
            }
        }
        quantity = std::stoi(s);
        if(quantity < 1){
            throw std::invalid_argument("quantity <= 0");
        }
    }

    void cart_action(cart_op_t op){
        std::string article;
        int quantity;
        bool action_success = false;
        bool input_success = false;
        
        while(!action_success) {
            try {
                input(article, quantity);
                input_success = true;
            }
            catch (std::invalid_argument &ex) {
                std::cerr << "Exception Input:" << ex.what() << std::endl;
            }
            if(input_success) {
                try {
                    if (pStock != nullptr && pCart != nullptr) {
                        if (op == CART_ADD) {
                            pStock->remove(article, quantity);
                            pCart->add(article, quantity);
                        }
                        else {
                            pCart->remove(article, quantity);
                            pStock->add(article, quantity);
                        }
                    }
                    action_success = true;
                }
                catch (std::runtime_error &ex) {
                    std::cerr << "Exception runtime_error:" << ex.what() << std::endl;
                }
            }
        }
    }

    static void info(){
        std::cout   << "Command list:\n"
                    << "\tinfo - show this list\n"
                    << "\tadd - for add to cart\n"
                    << "\tremove - for remote goods from cart\n"
                    << "\tadd_stock - add goods to the stock of shop\n"
                    << "\texit - for exit from program" << std::endl;
    }

public:

    void run(){
        info();
        std::string cmd;
        while(cmd != "exit"){
            std::cout   << "Enter command:";
            std::cin >> cmd;
            if(cmd == "info"){
                info();
            }
            else if(cmd == "add_stock"){
                add_to_stock();
                print_stock();
            }
            else if(cmd == "add") {
                cart_action(CART_ADD);
                print_stock();
                print_cart();
            }
            else if(cmd == "remove") {
                cart_action(CART_REMOVE);
                print_stock();
                print_cart();
            }
        }
    }

};

int main() {

    Shop shop;
    shop.run();

    return 0;
}
