#include <iostream>
#include <vector>

class PhoneBook{

    class Contacts{
    public:
        std::string name{};
        std::string number{};
    };

    std::vector<Contacts> contacts = {{"Sergey",  "+79876540000"},
                                      {"Anton",   "+79876542222"},
                                      {"Anna",    "+79876543333"}};

public:

    int findContact(std::string &name){
        for(int i{}; i < contacts.size(); i++){
            if(contacts[i].name == name) return i;
        }
        return -1;
    }

    void addContact(){
        Contacts p{};
        std::cout << "Enter name:";
        std::cin >> p.name;
        std::cout << "Enter phone number:";
        std::cin >> p.number;
        contacts.push_back(p);
    }

    std::string getName(int &index){
        return contacts[index].name;
    }

    std::string getNumber(int &index){
        return contacts[index].number;
    }
};

class Phone{
    PhoneBook phoneBook;

public:

    static std::string get_command(std::istream* cin){
        std::cout << "Enter command:";
        std::string s{};
        *(cin) >> s;
        return s;
    }

    void add(){
        phoneBook.addContact();
    }

    void call(){
        std::string name;
        std::cout << "Enter name:";
        std::cin >> name;
        int index = phoneBook.findContact(name);
        if(index >= 0){
            std::cout << "CALL >> " << phoneBook.getName(index) << " " << phoneBook.getNumber(index) << std::endl;
        }
        else std::cout << "Contact not found!" << std::endl;
    }

    void smsSend(){
        std::string name;
        std::cout << "Enter name:";
        std::cin >> name;
        int index = phoneBook.findContact(name);
        if(index >= 0){
            std::cin.ignore();
            std::cout << "Enter your message:";
            std::string sms;
            std::getline(std::cin, sms);
            std::cout   << "Send SMS: " << sms << "\n"
                        << "To: " << phoneBook.getName(index) << " " << phoneBook.getNumber(index) << std::endl;
        }
        else std::cout << "Contact not found!" << std::endl;
    }

};

int main() {
    std::cout << std::string(29,'=') << std::endl;
    std::cout << "Phone emulation program" << std::endl;
    std::cout << std::string(29,'=') << std::endl;

    Phone phone;
    std::string cmd;

    for(;;){

        cmd = Phone::get_command(&std::cin);

        if(cmd == "exit"){
            exit(0);
        }
        else if(cmd == "add"){
            phone.add();
        }
        else if(cmd == "call"){
            phone.call();
        }
        else if(cmd == "sms"){
            phone.smsSend();
        }
        else{
            std::cout << "Unknown command!" << std::endl;
        }
    }

}
