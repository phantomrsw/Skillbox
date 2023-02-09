#include <iostream>

#define DAY1 "Monday"
#define DAY2 "Tuesday"
#define DAY3 "Wednesday"
#define DAY4 "Thursday"
#define DAY5 "Friday"
#define DAY6 "Saturday"
#define DAY7 "Sunday"

#define GD(a) (a == 1 ? DAY1 : \
              (a == 2 ? DAY2 : \
              (a == 3 ? DAY3 : \
              (a == 4 ? DAY4 : \
              (a == 5 ? DAY5 : \
              (a == 6 ? DAY6 : \
              (a == 7 ? DAY7 : \
              "Incorrect number day!")))))))

int main() {

    for(;;){
        std::cout << "Enter number day:";
        int day;
        std::cin >> day;
        std::cout << GD(day) << std::endl;
    }

}
