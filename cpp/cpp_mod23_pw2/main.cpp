#include <iostream>

//#define SPRING
//#define SUMMER
//#define AUTUMN
//#define WINTER

#ifdef SPRING
  int main() {std::cout << "Season - SPRING\n";}
#elif SUMMER
  int main() {std::cout << "Season - SUMMER\n";}
#elif AUTUMN
  int main() {std::cout << "Season - AUTUMN\n";}
#elif WINTER
  int main() {std::cout << "Season - WINTER\n";}
#else
  int main() {std::cout << "Season UNDEFINED\n";}
#endif
