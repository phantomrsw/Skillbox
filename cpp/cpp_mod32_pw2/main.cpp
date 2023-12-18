#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>

struct person{
    std::string name;
    std::string family;
};

struct filmDesc{
    std::string country;
    int year;
    person mainRole;
};

struct listFilms{
    std::string title;
    filmDesc desc;
};

int main() {

    setlocale(LC_CTYPE, "Russian");

    std::ofstream file("films.json");
    nlohmann::json film = {
        {"Иван Васильевич меняет профессию",{
                {"Год",1973},
                {"Страна","CCCР"},
                {"Студия",""},
                {"Сценарий",""},
                {"Режиссер",{
                    {"Имя","Леонид"},
                    {"Фамилия","Гайдай"}
                }},
                {"Продюсер",""},
        }},

        {"Операция Ы и другие приключения Шурика",{
            {"Год",1965}
        }},

    };

    //film["Год"] = 1986;
    //film["Название"] = "Иван Васильевич меняет профессию";
    file << film;
    file.close();

    std::ifstream ifile("films.json");
    nlohmann::json ifilms;

    ifile >> ifilms;

    auto it = ifilms.find("Имя");

    std::cout << ifilms;

    return 0;
}
