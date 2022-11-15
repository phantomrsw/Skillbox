#include <iostream>
#include <fstream>

int main() {

    std::ifstream file;
    file.open("../words.txt");

    std::string word;
    std::cout << "What word are we looking for:";
    std::cin >> word;

    int count = 0;
    while(!file.eof()){
        std::string str;
        file >> str;
        if(str == word) count++;
    }

    std::cout << std::endl << "Repetitions of the word '" << word << "':" << count;

    file.close();
    return 0;
}
