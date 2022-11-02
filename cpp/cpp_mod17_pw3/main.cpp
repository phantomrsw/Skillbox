#include <iostream>
//#include <cstring>

bool substr(const char* s1, const char* s2){
    for(int i = 0; *(s1 + i) != '\0'; i++){
        if(*(s1 + i) == *(s2)){
            for(int j = 0; *(s2 + j) != '\0'; j++){
                if(*(s1 + i + j) != *(s2 + j)) return false;
            }
            return true;
        }
    }
    return false;
}

int main() {

    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";

    std::cout << substr(a,b) << " " << substr(a,c);

    return 0;
}
