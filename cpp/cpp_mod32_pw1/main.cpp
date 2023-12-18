#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>

int main() {

    std::ofstream file("film.json");
    nlohmann::json film;
    film["Title"] = "1 + 1";
    film["Country"] = "France";
    film["Date"] = "2011 year";
    film["Directors"] = "Olivier Nakache, Eric Toledano";
    film["Produced by"] = "Nicolas Duval-Adassovsky, Laurent Zeitoun, Ian Zenu";
    film["Screenplay by"] = "Olivier Nakache, Eric Toledano";
    film["Film studio"] = "Gaumont";
    film["Main characters"] = "The main characters are the aristocrat Philippe, who, as a result of an accident,"
             "ends up in a wheelchair. And Driss is a former petty criminal whom Philippe takes"
             "on as his assistant.";
    film["Main roles played by"] = "Francois Cluzet and Omar Sy";

    file << film;
    std::cout << film << std::endl;

    return 0;
}
