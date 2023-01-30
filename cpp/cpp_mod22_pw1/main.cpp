#include <iostream>
#include <sstream>
#include <map>

enum enum_req_t{
    REQ_INCORRECT = 0,
    REQ_ADD_TO_PHONEBOOK = 1,
    REQ_GET_LASTNAME = 2,
    REQ_GET_NUMBER = 3
};

typedef struct{
    enum_req_t type;
    std::string name;
    std::string phoneNumber;
}request_t;

request_t request = {REQ_INCORRECT,"",""};

bool this_string_is_char(std::string& s){
    for(char i : s) if(!isalpha(i)) return false;
    return true;
}

int check_request(std::string& n, request_t* r){

    std::stringstream b (n);

    if(n.length() >= 8 && n[2] == '-' && n[5] == '-' &&
        isdigit(n[0]) && isdigit(n[1]) &&
        isdigit(n[3]) && isdigit(n[4]) &&
        isdigit(n[6]) && isdigit(n[7])){

        if(n.length() == 8){
            b >> r->phoneNumber;
            r->type = REQ_GET_LASTNAME;
        }
        else{
            b >> r->phoneNumber >> r->name;
            r->type = REQ_ADD_TO_PHONEBOOK;
        }
    }
    else if(n.length() > 1 && this_string_is_char(n)){
        b >> r->name;
        r->type = REQ_GET_NUMBER;
    }
    else r->type = REQ_INCORRECT;

    return r->type;
}

int main() {
    std::cout << "====================Phonebook program====================\n"
              << " Possible request formats:\n"
              << " 69-70-30 Ivanov - add number and last name to phone book\n"
              << " 69-70-30 - find last name by phone number\n"
              << " Ivanov - find a number by last name\n"
              << "=========================================================" << std::endl;

    std::map<std::string, std::string> phoneBook;

    for(;;){
        std::cout << "Enter your request:";
        std::string input;
        std::getline(std::cin, input);

        while (check_request(input, &request) == REQ_INCORRECT) {
            std::cout << "Your request incorrect! Enter again:";
            std::getline(std::cin, input);
        }

        /*std::cout << "Type:" << request.type << " "
                  << "Name:" << request.name << " "
                  << "Phone number:" << request.phoneNumber << std::endl;*/
        if (request.type == REQ_ADD_TO_PHONEBOOK) {

            phoneBook.insert(std::pair<std::string, std::string>(request.phoneNumber, request.name));
            /*std::cout << phoneBook.size() << std::endl;
            for (auto it = phoneBook.begin();
                    it != phoneBook.end(); it++) {
                std::cout << it->first << " " << it->second << std::endl;
            }*/
        }
        else if (request.type == REQ_GET_LASTNAME) {
            auto it = phoneBook.find(request.phoneNumber);
            /*Method find() return past-the-end (see end()) value if no such element is found.*/
            /*In this case, the standard output for such an iterator may lead to an incorrect */
            /*termination of the program.                                                     */
            if(it != phoneBook.end()) std::cout << it->second << std::endl;
            else std::cout << "There are no records for this phone number!" << std::endl;
        }
        else if (request.type == REQ_GET_NUMBER) {
            bool record_find = false;
            for (auto & it : phoneBook) {
                if(it.second == request.name) {
                    std::cout << it.first << " " << std::endl;
                    record_find = true;
                }
            }
            if(!record_find) std::cout << "There are no records for this last name." << std::endl;
        }
    }

}
