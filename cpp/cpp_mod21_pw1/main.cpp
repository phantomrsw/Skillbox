#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

bool check_name(std::string name){
    bool status = true;
    std::string s;
    if(name.length() < 2){
        s += "Name length cannot be less than 2 characters!\n";
        status = false;
    }
    if(name[0] < 'A' || name[0] > 'Z'){
        s += "The first letter in the name can only be capitalized!\n";
        status = false;
    }
    for(int i = 1; i < name.length(); i++) {
        if(name[i] < 'a' || name[i] > 'z' ){
            s += "Name can only contain letters!\n";
            status = false;
        }
    }
    if(!status) std::cout << "Incorrect input!\n" << s << "Enter again:";

    return status;
}

bool check_payment(std::string pay){
    for (auto e: (pay))
        if (!isdigit(e)) {
            std::cout << "Incorrect input! Payment must be entered as numbers! Enter again:";
            return false;
        }
    return true;
}

bool check_date(std::string date){
    bool status = true;
    std::string s;
    if(date.length() != 10){
        s += "Length of date is incorrect!\n";
        status = false;
    }
    if(date[2] != '.' || date[5] != '.'){
        s += "Separator must be a point!\n";
        status = false;
    }
    int day = std::stoi(date.substr(0,2));
    int month = std::stoi(date.substr(3,2));
    const int daysPerMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(month < 1 || month > 12){
        s += "Month number is not correct!\n";
        status = false;
    }
    else if(day < 1 || day > daysPerMonth[month - 1]){
        s += "Day number is not correct!\n";
        status = false;
    }

    if(!status) std::cout << "Incorrect input!\n" << s << "Enter again:";

    return status;
}

bool check_command(std::string cmd){
    if(cmd != "list" && cmd != "add") {
        std::cout << R"(Incorrect command(Should be "list" or "add" ). Enter again:)";
        return false;
    }
    else return true;
}

bool (*ptr_check_name)(std::string){check_name};
bool (*ptr_check_payment)(std::string){check_payment};
bool (*ptr_check_date)(std::string){check_date};
bool (*ptr_check_command)(std::string){check_command};

void input_data(const char* inputLine, std::string* data, bool(*check_func)(std::string)){
    std::cout << inputLine;
    std::cin >> *data;
    while(!check_func(*data)){
        std::cin >> *data;
    }
}

int main() {

    struct record_t {
        std::string firstName;
        std::string lastName;
        std::string payment;
        std::string date;
    };
    std::vector<record_t> records;

    std::string command;
    input_data("Enter command:", &command, ptr_check_command);

    if(command == "list"){
        std::ifstream file;

        file.open("../paymentStatement.txt");
        if(!file.is_open()){
            std::cout << "Fail open file: " << std::strerror(errno) << std::endl;
            return errno;
        }

        while(!file.eof()){
            record_t temp;
            file >> temp.firstName >> temp.lastName >> temp.payment >> temp.date;
            if(!temp.firstName.empty()) records.push_back(temp);
        }

        file.close();

        for(auto & i : records)
            std::cout   << i.firstName  << " "
                        << i.lastName   << " "
                        << i.payment    << " "
                        << i.date       << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "Read total " << records.size() << " records." << std::endl;
    }
    else if(command == "add"){
        if(!records.empty()) records.clear();
        record_t temp;

        input_data("Enter first name:", &temp.firstName, ptr_check_name);
        input_data("Enter last name:", &temp.lastName, ptr_check_name);
        input_data("Enter payment:", &temp.payment, ptr_check_payment);
        input_data("Enter date(DD.MM.YYYY):", &temp.date, ptr_check_date);

        std::ofstream file;

        file.open("../paymentStatement.txt",std::ios::app);
        if(!file.is_open()){
            std::cout << "Fail open file: " << std::strerror(errno) << std::endl;
            return errno;
        }
        file    << temp.firstName << " "
                << temp.lastName  << " "
                << temp.payment   << " "
                << temp.date      << std::endl;

        file.close();
    }

    return 0;
}
