#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    std::ifstream file;
    std::string path = "../paymentStatement.txt";

    file.open(path);

    int payment = 0, totalPayment = 0;
    std::string firstName, lastName, data;

    while(!file.eof()){
        std::string s;
        std::string fn, ln, d;
        int p;

        std::getline(file,s);
        std::stringstream buf(s);
        buf >> fn >> ln >> p >> d;

        if(p > payment) {
            payment = p;
            firstName = fn;
            lastName = ln;
            data = d;
        }
        totalPayment += p;
    }

    std::cout << "Max payment:" << firstName << " " << lastName << " " << payment << " " << data << std::endl;
    std::cout << "Total payment:" << totalPayment;

    file.close();
    return 0;
}
