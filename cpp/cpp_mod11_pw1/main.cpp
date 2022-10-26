#include <iostream>

std::string encrypt_caesar(std::string &str, int n){
    std::string strOut = str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            if(str[i] - 'A' + n >= 0){
                strOut[i] = (char)('A' + (str[i] - 'A' + n)%26);
            }
            else strOut[i] = (char)('Z' + (str[i] - 'A' + n)%26 + 1);
        }
        else if(str[i] >= 'a' && str[i] <= 'z'){
            if(str[i] - 'a' + n >= 0){
                strOut[i] = (char)('a' + (str[i] - 'a' + n)%26);
            }
            else strOut[i] = (char)('z' + (str[i] - 'a' + n)%26 + 1);
        }
    }
    return strOut;
}
std::string decrypt_caesar(std::string str, int n){
    return encrypt_caesar(str,-n);
}
int main() {
    std::cout << "Enter text for encrypt:" << std::endl;
    std::string s;
    std::getline (std::cin,s);

    std::cout << "Enter key:" << std::endl;
    int key;
    std::cin >> key;

    std::cout << "Encrypted: \n" << encrypt_caesar(s,key) << std::endl;
    std::cout << "Decrypted: \n" << decrypt_caesar(encrypt_caesar(s,key),key) << std::endl;

    return 0;
}
