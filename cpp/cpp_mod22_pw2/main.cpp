#include <iostream>
#include <map>

bool this_string_is_char(std::string& s){
    for(char i : s) if(!isalpha(i)) return false;
    return true;
}

int main() {
    std::cout << "====================Registry program=====================\n"
              << " You can enter the last name or the command:\n"
              << " Ivanov - add last name to queue\n"
              << " Next - Send the first person in line to the front desk\n"
              << " exit - for terminated this program\n"
              << "=========================================================" << std::endl;

    std::map<std::string, std::string> registry;

    int count_queue = 0;

    for(;;){
        std::cout << "Enter last name or command:";
        std::string input;
        std::cin >> input;

        while (!this_string_is_char(input)) {
            std::cout << "Your request incorrect! Enter again:";
            std::cin >> input;
        }

        if(input == "Next"){
            if(!registry.empty()) registry.erase(registry.begin());
        }
        else if(input == "exit"){
            exit(0);
        }
        else{
            registry.insert(std::pair<std::string, std::string>(input + std::to_string(count_queue), input));
            count_queue++;
        }

        std::cout << "=== Queue ===" << std::endl;
        for(auto it = registry.begin(); it != registry.end(); it++){
            std::cout << it->second << std::endl;
        }

    }

}
