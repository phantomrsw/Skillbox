#include <iostream>
#include <cstring>
#include <fstream>

bool check_name(std::string &name){
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

bool check_payment(std::string &pay){
    for (auto e: pay)
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

int main() {

    std::string firstName = "Sergey",
                lastName = "Rygin",
                payment = "21500",
                date = "21.11.2022";

    std::cout << "Enter first name:";
    std::cin >> firstName;
    while(!check_name(firstName)){
        std::cin >> firstName;
    }

    std::cout << "Enter last name:";
    std::cin >> lastName;
    while(!check_name(lastName)) {
        std::cin >> lastName;
    }

    std::cout << "Enter payment:";
    std::cin >> payment;
    while(!check_payment(payment)){
        std::cin >> payment;
    }

    std::cout << "Enter date(DD.MM.YYYY):";
    std::cin >> date;
    while(!check_date(date)){
        std::cin >> date;
    }

    std::ofstream file;

    file.open("../paymentStatement.txt",std::ios::app);
    if(!file.is_open()){
        std::cout << "Fail open file: " << std::strerror(errno) << std::endl;
        return errno;
    }
    file << firstName << " " << lastName << " " << payment << " " << date << std::endl;

    file.close();

    return 0;
}