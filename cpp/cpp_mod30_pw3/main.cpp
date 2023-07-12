#include <iostream>
#include <map>
#include <cpr/cpr.h>

int main() {

    std::string arg,val;
    std::map<std::string,std::string> m;
    cpr::Response r;

    for(;;){
        std::cout << "Enter the argument name :";
        std::cin >> arg;
        if(arg == "post" || arg == "get") break;
        std::cout << "Enter the argument value:";
        std::cin >> val;
        m.insert(std::pair<std::string, std::string>(arg, val));
    }

    if(arg == "get"){
        std::string getUrl = "http://httpbin.org/get?";
        for(auto & it : m){
            getUrl += it.first + "=" + it.second + "&";
        }
        r = cpr::Get(cpr::Url(getUrl));
    }
    else{/*post*/
        std::vector<cpr::Pair> pair;
        for (auto & it : m){
            pair.emplace_back(it.first,it.second);
        }
        cpr::Payload payload = cpr::Payload(pair.begin(),pair.end());
        r = cpr::Post(cpr::Url{"http://httpbin.org/post"},payload);
    }

    std::cout << "Status: " << r.status_code << " " << r.reason << "\n" << r.text;

    return 0;
}
