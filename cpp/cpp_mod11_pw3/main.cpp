#include <iostream>

std::string getAddressPart(std::string &s, int n){
    int countPoint = 0;
    std::string sOut;
    for(int i = 0; i < s.length(); i++){
        if (s[i] == '.' && countPoint < 3) countPoint ++;
        else if (countPoint > n) break;
        else if(countPoint == n) sOut += s[i];
    }
    return sOut;
}

bool checkOctet(std::string s){
    if(s.length() > 3 || s.length() < 1) return false;

    for(int i = 0; i < s.length(); i++){
        if(s[i] < '0' || s[i] > '9') return false;
    }

    if((s.length() == 3 && (s[0] == '0' || (s[0] == '0' && s[1] == '0'))) ||
            (s.length() == 2 && s[0] == '0')) return false;

    if(std::stoi(s) < 0 || std::stoi(s) > 255) return false;
    else return true;
}

int main() {
    std::cout << "Enter IP address:" << std::endl;
    std::string ip;
    std::getline(std::cin,ip);

    bool valid = true;
    for(int i = 0; i < 4; i++)
    {
        if(!checkOctet(getAddressPart(ip,i))) valid = false;
    }

    if(valid) std::cout << "IP address Valid!";
    else std::cerr << "IP address Invalid!";

    return 0;
}
