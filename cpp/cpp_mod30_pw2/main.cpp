#include <iostream>
#include <cpr/cpr.h>

int main() {

    cpr::Response r = cpr::Get(cpr::Url{"http://httpbin.org/html"},
                 cpr::Header{{"accept","text/html"}});
    std::cout << "Status:" << r.status_code << " " << r.reason << std::endl;
    std::cout << "Elapsed time:" << r.elapsed << std::endl;
    //std::cout << r.text << std::endl;

    for(auto i = r.text.find("<h1>"); i != r.text.find("</h1>"); i++){
        if(i == r.text.find("<h1>")) i += 3;
        else std::cout << r.text[i];
    }

    return 0;
}
