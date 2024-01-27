#include <iostream>
#include <vector>

template<typename K, typename V>
struct List_t{
public:
    K key;
    V value;
    List_t(K &_k,V &_v):key(_k),value(_v){};
};

template<typename K, typename V>
class Registry{

    std::vector<List_t<K,V>> list;
    K key{};
    V value{};

public:

    Registry() = default;

    std::string get_command(std::istream* cin){
        std::cout << "Enter command:";
        std::string s{};
        *(cin) >> s;
        return s;
    }

    void add(){
        std::cout << "Enter key:";
        std::cin >> key;
        std::cout << "Enter value:";
        std::cin >> value;
        List_t l(key,value);
        list.push_back(l);
    }

    void remove(){
        if(!list.empty()) {
            int count{};
            std::cout << "Enter the key of the component to be removed:";
            std::cin >> key;
            for(auto it = list.begin(); it < list.end(); it++){
                if(it->key == key){
                    list.erase(it);
                    it--;
                    count++;
                }
            }
            if(count){
                std::cout << "Removed " << count << " components" << std::endl;
            }
            else{
                std::cout << "No such key found!" << std::endl;
            }
        }
        else{
            std::cout << "Registry is empty." << std::endl;
        }
    }

    void print(){
        if(!list.empty()){
            for(auto &l : list){
                std::cout << "key=" << l.key << " " << "value=" << l.value << std::endl;
            }
        }
        else{
            std::cout << "Registry is empty." << std::endl;
        }
    }

    void find(){
        if(!list.empty()){
            bool find = false;
            std::cout << "Enter the element key:";
            std::cin >> key;
            for (auto &l: list) {
                if(l.key == key){
                    std::cout << "key=" << l.key << " " << "value=" << l.value << std::endl;
                    find = true;
                }
            }

            if(!find){
                std::cout << "No such key found!" << std::endl;
            }

        }
        else{
            std::cout << "Registry is empty." << std::endl;
        }
    }
};

int main() {

    auto* pRegistry = new Registry<int,std::string>;

    std::string cmd;

    for(;;){

        cmd = pRegistry->get_command(&std::cin);

        if(cmd == "exit"){
            delete pRegistry;
            exit(0);
        }
        else if(cmd == "add"){
            pRegistry->add();
        }
        else if(cmd == "remove"){
            pRegistry->remove();
        }
        else if(cmd == "print"){
            pRegistry->print();
        }
        else if(cmd == "find"){
            pRegistry->find();
        }
        else{
            std::cout << "Unknown command!" << std::endl;
        }
    }

}
