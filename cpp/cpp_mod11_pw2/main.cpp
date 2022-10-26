#include <iostream>
#include <cctype>

std::string UpperToLower(std::string s){
    std::string sOut = s;
    for(int i = 0; i < s.length(); i++) {
        //if(std::isupper(s[i])) sOut[i] = std::tolower(s[i]);
        if(std::isupper(s[i])) sOut[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
    }
    return sOut;
}

std::string getFirstPart(std::string &s){
    std::string sOut;
    for(int i = 0; s[i] != '@' && i < s.length(); i++) sOut += s[i];
    return sOut;
}
std::string getSecondPart(std::string &s){
    std::string sOut;
    bool start = false;
    for(int i = 0; i < s.length(); i++){
        if(s[i-1] == '@') start = true;
        if(start) sOut += s[i];
    }
    return sOut;
}

int checkFirstPart(std::string s){
    int errCode = 0;
    std::string dictCharFirst =  "abcdefghijklmnopqrstuvwxyz0123456789-.!#$%&'*+-/=?^_`{|}~";
    if(s.length() < 1 || s.length() > 64) errCode = 1;
    else if(s[0] == '.'){
        errCode = 2;
    }
    else{
        for(int i = 0; i < s.length(); i++){
            bool charFind = false;
            for(int j = 0; j < dictCharFirst.length(); j++){
                if(s[i] == dictCharFirst[j]) {
                    charFind = true;
                    break;
                }
            }
            if(!charFind || (s[i] == '.' && s[i+1] == '.')) {
                errCode = 3;
                break;
            }
        }
    }
    return errCode;
}

int checkSecondPart(std::string s){
    int errCode = 0;
    std::string dictCharSecond = "abcdefghijklmnopqrstuvwxyz0123456789-.";
    if(s.length() < 1 || s.length() > 63) errCode = 1;
    else if(s[s.length()-1] == '.'){
        errCode = 2;
    }
    else{
        for(int i = 0; i < s.length(); i++){
            bool charFind = false;
            for(int j = 0; j < dictCharSecond.length(); j++){
                if(s[i] == dictCharSecond[j]) {
                    charFind = true;
                    break;
                }
            }
            if(!charFind || (s[i] == '.' && s[i+1] == '.') || s[i] == '@') {
                errCode = 3;
                break;
            }
        }
    }
    return errCode;
}

int main() {
    std::cout << "Enter e-mail:" << std::endl;
    std::string email;
    std::getline (std::cin,email);

    email = UpperToLower(email);

    //std::cout << "First part:" << getFirstPart(email) << std::endl;
    //std::cout << "Second part:" << getSecondPart(email) << std::endl;

    int errorFirstPart = checkFirstPart(getFirstPart(email));
    int errorSecondPart = checkSecondPart(getSecondPart(email));

    if (errorFirstPart) {
        std::cerr << "NO! First part of email invalid! (code:" << errorFirstPart << ")" << std::endl;
    }
    else if(errorSecondPart) {
        std::cerr << "NO! Second part of email invalid! (code:" << errorSecondPart << ")" << std::endl;
    }
    else std::cout << "YES! e-mail is valid!";
    return 0;
}
