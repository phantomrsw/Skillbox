#include <iostream>
#include <map>
#include <sstream>

bool check_anagram(std::string &s1, std::string &s2){

    std::map<std::string,char> m1,m2;

    int i = 0;
    for(char ch : s1) m1.insert(std::pair<std::string,char>(ch + std::to_string(i++),ch));
    for(char ch : s2) m2.insert(std::pair<std::string,char>(ch + std::to_string(i++),ch));

    /*std::cout << "size m1:" << m1.size() << std::endl;
    for (auto it = m1.begin(); it != m1.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;
    std::cout << "size m2:" << m2.size() << std::endl;
    for (auto it = m2.begin(); it != m2.end(); it++)
        std::cout << it->first << " " << it->second << std::endl;*/

    if(m1.size() == m2.size()){
        std::map<std::string,char>::iterator it1 = m1.begin();
        std::map<std::string,char>::iterator it2 = m2.begin();
        for(;it1 != m1.end();){
            if(it1->second != it2->second) return false;
            it1++;
            it2++;
        }
        return true;
    }
    return false;
}

int main() {
    std::cout << "Enter two words: " << std::endl;
    std::string input, s1, s2;
    std::getline(std::cin, input);
    std::stringstream b (input);
    b >> s1 >> s2;

    if(check_anagram(s1,s2)) std::cout << "These words are anagrams!" << std::endl;
    else std::cout << "These words are NOT anagrams!" << std::endl;

    return 0;
}
