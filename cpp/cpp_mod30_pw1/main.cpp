#include <iostream>
#include <cpr/cpr.h>

cpr::Response r;

void show_response(cpr::Response &resp){
    std::cout << "Status: " << resp.status_code << " " << resp.reason << std::endl;
    std::cout << "Elapsed time:" << resp.elapsed << std::endl;
    std::cout << "Text:\n" << resp.text << std::endl;
}

int main() {

    for(;;){
        std::string cmd;
        std::cout << "Enter command:";
        std::cin >> cmd;
        if(cmd == "get"){
            /*Get without parameters and with timeout response*/
            r = cpr::Get(cpr::Url{"http://httpbin.org/get"},cpr::Timeout{100});
            show_response(r);
            /*Get with parameters*/
            cpr::Parameters parameters = cpr::Parameters{{"arg1","value1"},{"arg2","value2"}};
            r = cpr::Get(cpr::Url{"http://httpbin.org/get"}, parameters);
            show_response(r);
        }
        else if(cmd == "post"){
            /*This sends up "key=value" as a "x-www-form-urlencoded" pair in the POST request*/
            cpr::Payload payload = cpr::Payload{{"First name","Sergey"},{"Last name","Rygin"}};
            r = cpr::Post(cpr::Url{"http://httpbin.org/post"},payload);
            show_response(r);
            /*To send data raw and unencoded, use Body which takes std::string
             * or std::string_view as parameter instead of Payload:*/
            r = cpr::Post(cpr::Url{"http://httpbin.org/post"},
                          cpr::Body{"This is raw POST data"},
                          cpr::Header{{"Content-Type", "text/plain"}});
            show_response(r);
        }
        else if(cmd == "put"){
            /*PUT Used when you need to completely replace an object on the server,
             * unlike POST which creates a new object every time*/
            cpr::Payload payload = cpr::Payload{{"Tel1:","+74951234567"},{"Tel2:","+74959999999"}};
            r = cpr::Put(cpr::Url{"http://httpbin.org/put"},payload);
            show_response(r);
        }
        else if(cmd == "delete"){
            cpr::File file = cpr::File{"old_file.txt"};
            r = cpr::Delete(cpr::Url{"http://www.httpbin.org/delete"},file);
            show_response(r);
        }
        else if(cmd == "patch"){
            /*PATCH is used if you need to update the object partially and if it is supported by the API*/
            r = cpr::Patch(cpr::Url{"http://www.httpbin.org/patch"},
                           cpr::Payload{{"key", "value"}});
            show_response(r);
        }
        else if(cmd == "exit"){
            return 0;
        }
        else {
            std::cout << "Unknown command" << std::endl;
        }

    }

}
