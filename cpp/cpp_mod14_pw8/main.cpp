#include <iostream>
#include <chrono>
#include <thread>

char field[2][10][10];
const char charShip[] = {'S','D','T','Q'};
int queue = 0;

char get_ascii_symbol_point_on_center(int n){
    /*switch (n)
    {                               *//*UTF8 2 byte - Symbol - ascii*//*
        case 183: return (char)250; *//*194 183     -   ·    - 250  *//*
        default: return ' ';
    }*/
    return n == 183 ? (char)250 : ' ';
}

char get_ascii_symbol_frame(int n){
    switch (n)
    {                               /*UTF8 3 byte - Symbol - ascii*/
        case 128: return (char)196; /*226 148 128 -   ─    - 196  */
        case 130: return (char)179; /*226 148 130 -   │    - 179  */
        case 188: return (char)197; /*226 148 188 -   ┼    - 197  */
        case 156: return (char)195; /*226 148 156 -   ├    - 195  */
        case 164: return (char)180; /*226 148 164 -   ┤    - 180  */
        case 172: return (char)194; /*226 148 172 -   ┬    - 194  */
        case 180: return (char)193; /*226 148 180 -   ┴    - 193  */
        case 140: return (char)218; /*226 148 140 -   ┌    - 218  */
        case 144: return (char)191; /*226 148 144 -   ┐    - 191  */
        case 148: return (char)192; /*226 148 148 -   └    - 192  */
        case 152: return (char)217; /*226 148 152 -   ┘    - 217  */
        default: return ' ';
    }
}

char get_ascii_symbol_double_frame(int n){
    switch (n)
    {                               /*UTF8 3 byte - Symbol - ascii*/
        case 144: return (char)205; /*226 149 144 -   ═    - 205  */
        case 145: return (char)186; /*226 149 145 -   ║    - 186  */
        case 172: return (char)206; /*226 149 172 -   ╬    - 206  */
        case 160: return (char)204; /*226 149 160 -   ╠    - 204  */
        case 163: return (char)185; /*226 149 163 -   ╣    - 185  */
        case 166: return (char)203; /*226 149 166 -   ╦    - 203  */
        case 169: return (char)202; /*226 149 169 -   ╩    - 202  */
        case 148: return (char)201; /*226 149 148 -   ╔    - 201  */
        case 151: return (char)187; /*226 149 151 -   ╗    - 187  */
        case 154: return (char)200; /*226 149 154 -   ╚    - 200  */
        case 157: return (char)188; /*226 149 157 -   ╝    - 188  */
        default: return ' ';
    }
}

char get_ascii_symbols_blocks(int n){
    switch(n)
    {                               /*UTF8 3 byte - Symbol - ascii*/
        case 136: return (char)219; /*226 150 136 -   █    - 219  */
        case 132: return (char)220; /*226 150 132 -   ▄    - 220  */
        case 128: return (char)223; /*226 150 128 -   ▀    - 223  */
        case 140: return (char)221; /*226 150 140 -   ▌    - 221  */
        case 144: return (char)222; /*226 150 144 -   ▐    - 222  */
        default: return ' ';
    }
}

std::string utf8_to_ascii(std::string s){
    std::string sOut;

    uint8_t sLength = s.length();
    for(int i = 0; i < sLength; i++){
        if(((uint8_t)s[i]) == 194){
            sOut += get_ascii_symbol_point_on_center((uint8_t)s[i + 1]);
            i += 1;
        }
        else if(((uint8_t)s[i]) == 226 && ((uint8_t)s[i + 1]) == 148){
            sOut += get_ascii_symbol_frame((uint8_t)s[i + 2]);
            i += 2;
        }
        else if(((uint8_t)s[i]) == 226 && ((uint8_t)s[i + 1]) == 149){
            sOut += get_ascii_symbol_double_frame((uint8_t)s[i + 2]);
            i += 2;
        }
        else if(((uint8_t)s[i]) == 226 && ((uint8_t)s[i + 1]) == 150){
            sOut += get_ascii_symbols_blocks((uint8_t)s[i + 2]);
            i += 2;
        }
        else sOut += s[i];
    }
    return sOut;
}

void print_banner(){

    const std::string s[6] = \
    {{utf8_to_ascii("\n██████╗  █████╗ ████████╗████████╗██╗     ███████╗███████╗██╗  ██╗██╗██████╗ ")},
     {utf8_to_ascii("\n██╔══██╗██╔══██╗╚══██╔══╝╚══██╔══╝██║     ██╔════╝██╔════╝██║  ██║██║██╔══██╗")},
     {utf8_to_ascii("\n██████╔╝███████║   ██║      ██║   ██║     █████╗  ███████╗███████║██║██████╔╝")},
     {utf8_to_ascii("\n██╔══██╗██╔══██║   ██║      ██║   ██║     ██╔══╝  ╚════██║██╔══██║██║██╔═══╝ ")},
     {utf8_to_ascii("\n██████╔╝██║  ██║   ██║      ██║   ███████╗███████╗███████║██║  ██║██║██║     ")},
     {utf8_to_ascii("\n╚═════╝ ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚══════╝╚══════╝╚══════╝╚═╝  ╚═╝╚═╝╚═╝     \n")}};

int i = 0;
    for(const auto & e : s){
        std::cout << s[i++];
    }
    std::this_thread::sleep_for(std::chrono::milliseconds (2000));
}

void print_winner(int numPlayer){

    const std::string s1[6] = \
    {{utf8_to_ascii("\n██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗      ██╗    ██╗    ██╗██╗███╗   ██╗███████╗██╗")},
     {utf8_to_ascii("\n██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ███║    ██║    ██║██║████╗  ██║██╔════╝██║")},
     {utf8_to_ascii("\n██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝    ╚██║    ██║ █╗ ██║██║██╔██╗ ██║███████╗██║")},
     {utf8_to_ascii("\n██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗     ██║    ██║███╗██║██║██║╚██╗██║╚════██║╚═╝")},
     {utf8_to_ascii("\n██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║     ██║    ╚███╔███╔╝██║██║ ╚████║███████║██╗")},
     {utf8_to_ascii("\n╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝     ╚═╝     ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝\n")}};

    const std::string s2[6] = \
    {{utf8_to_ascii("\n██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗     █████╗    ██╗    ██╗██╗███╗   ██╗███████╗██╗")},
     {utf8_to_ascii("\n██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗    ╚═══██╗   ██║    ██║██║████╗  ██║██╔════╝██║")},
     {utf8_to_ascii("\n██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝     ████╔╝   ██║ █╗ ██║██║██╔██╗ ██║███████╗██║")},
     {utf8_to_ascii("\n██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗    ██╔══╝    ██║███╗██║██║██║╚██╗██║╚════██║╚═╝")},
     {utf8_to_ascii("\n██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║    ██████║   ╚███╔███╔╝██║██║ ╚████║███████║██╗")},
     {utf8_to_ascii("\n╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝    ╚═════╝    ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝╚══════╝╚═╝\n")}};
    int i = 0;
    if(numPlayer - 1)for(const auto & e : s2) std::cout << s2[i++];
    else for(const auto & e : s1) std::cout << s1[i++];

    std::this_thread::sleep_for(std::chrono::milliseconds (2000));
}

void print_field(int numPlayer) {
    std::string s[] = {
        {utf8_to_ascii("              x                                x               Ships: \n")},
        {utf8_to_ascii("    ╔0-1-2-3-4-5-6-7-8-9╗            ╔0-1-2-3-4-5-6-7-8-9╗            \n")},
        {utf8_to_ascii("   0║· · · · · · · · · ·║0          0║· · · · · · · · · ·║0    4x S   \n")},
        {utf8_to_ascii("   1║· · · · · · · · · ·║1          1║· · · · · · · · · ·║1    3x DD  \n")},
        {utf8_to_ascii("   2║· · · · · · · · · ·║2          2║· · · · · · · · · ·║2    2x TTT \n")},
        {utf8_to_ascii("   3║· · · · · · · · · ·║3          3║· · · · · · · · · ·║3    1x QQQQ\n")},
        {utf8_to_ascii(" y 4║· · · · · · · · · ·║4        y 4║· · · · · · · · · ·║4           \n")},
        {utf8_to_ascii("   5║· · · · · · · · · ·║5          5║· · · · · · · · · ·║5           \n")},
        {utf8_to_ascii("   6║· · · · · · · · · ·║6          6║· · · · · · · · · ·║6           \n")},
        {utf8_to_ascii("   7║· · · · · · · · · ·║7          7║· · · · · · · · · ·║7           \n")},
        {utf8_to_ascii("   8║· · · · · · · · · ·║8          8║· · · · · · · · · ·║8           \n")},
        {utf8_to_ascii("   9║· · · · · · · · · ·║9          9║· · · · · · · · · ·║9           \n")},
        {utf8_to_ascii("    ╚0-1-2-3-4-5-6-7-8-9╝            ╚0-1-2-3-4-5-6-7-8-9╝            \n")},
        {utf8_to_ascii("           Player 1                         Player 2                  \n\n")}};

    std::string s3[3] = {"   ",">>>","<<<"};
    int i = 0;
    for(auto e : s3)s[13][i+29] = s3[numPlayer][i++];

    std::system("cls");

    for(i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            s[i + 2][2 * j + 5] = field[0][i][j];/*for field Player 1*/
            s[i + 2][2 * j + 38] = field[1][i][j];/*for field Player 2*/
        }
    }

    i = 0;
    for(const auto & e : s) std::cout << s[i++];
}

int check_coordinate(int numPlayer, int i, int x0, int y0, int x1, int y1){
    if(x0 > x1) std::swap(x0, x1);
    if(y0 > y1) std::swap(y0, y1);
    if(x0 < 0 || x0 > 9 || y0 < 0 || y0 > 9) {
        std::cout << "Coordinate x0 y0 are out of bounds!" << std::endl;
        return 1;
    }
    else if(x1 < 0 || x1 > 9 || y1 < 0 || y1 > 9) {
        std::cout << "Coordinate x1 y1 are out of bounds!" << std::endl;
        return 2;
    }
    else if(!(x1 - x0 == i && y0 == y1) &&
            !(y1 - y0 == i && x0 == x1)) {
        std::cout << "Coordinate (x0 y0) and (x1 y1) incorrect for " << i+1 <<"-deck ship!" << std::endl;
        return 3;
    }
    for(int j = x0; j <= x1; j++){
        for(int k = y0; k <= y1; k++){
            for(char c : charShip) if(field[numPlayer][k][j] == c) {
                std::cout << "Ships crossing!" << std::endl;
                return 4;
            }
        }
    }
    return 0;
}

void place_one_ship(int numPlayer, int typeShip, int x0, int y0, int x1, int y1){
    if(x0 > x1) std::swap(x0, x1);
    if(y0 > y1) std::swap(y0, y1);
    for(int i = x0; i <= x1; i++){
        for(int j = y0; j <= y1; j++){
            field[numPlayer][j][i] = charShip[typeShip];
        }
    }
}

void place_ships(int numPlayer){
    int x0, y0, x1 = 0, y1 = 0;
    for(int i = 0; i < 4; i++){
        for(int j = i; j < 4; j++){
            std::cout << "Player " << numPlayer + 1 <<", enter coordinate for " << i+1 << "-deck ship(x0 y0):";
            std::cin >> x0 >> y0;
            x1 = x0;
            y1 = y0;
            if(i){
                std::cout << "Player " << numPlayer + 1 <<", enter coordinate for " << i+1 << "-deck ship(x1 y1):";
                std::cin >> x1 >> y1;
            }
            while(check_coordinate(numPlayer, i, x0, y0, x1, y1)){
                std::cout << "Incorrect coordinate! Enter again(x0 y0):";
                std:: cin >> x0 >> y0;
                x1 = x0;
                y1 = y0;
                if(i){
                    std::cout << "Incorrect coordinate! Enter again(x1 y1):";
                    std:: cin >> x1 >> y1;
                }
            }
            place_one_ship(numPlayer,i,x0,y0,x1,y1);
            print_field(0);
        }
    }
}

bool strike(int numPlayer){
    int x, y;
    bool result = false;
    print_field(numPlayer + 1);
    std::cout << "Player " << numPlayer + 1 << ", enter strike coordinate(x y):";
    std::cin >> x >> y;
    while(x < 0 || x > 9 || y < 0 || y > 9){
        std::cout << "Incorrect coordinate! Enter again:";
        std:: cin >> x >> y;
    }
    if(numPlayer){/*Player 2*/
        if(field[0][y][x] == (char)250 || field[0][y][x] == '*' || field[0][y][x] == ' ') field[0][y][x] = '*';
        else {
            field[0][y][x] = ' ';
            result = true;
        }
    }
    else {/*Player 1*/
        if(field[1][y][x] == (char)250 || field[1][y][x] == '*' || field[1][y][x] == ' ') field[1][y][x] = '*';
        else {
            field[1][y][x] = ' ';
            result = true;
        }
    }
    //print_field();
    print_field(numPlayer + 1);
    return result;
}

void init_field(char s[2][10][10]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 2; k++) s[k][i][j] = (char)250;//ascii symbol '·'
        }
    }
}

int check_winner(){
    int winner = 1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(char c : charShip) if(field[1][i][j] == c) winner = 0;
        }
    }
    if(winner) return winner;
    winner = 2;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(char c : charShip) if(field[0][i][j] == c) winner = 0;
        }
    }
    return winner;
}

int main() {
    init_field(field);

    print_banner();
    print_field(0);

    place_ships(0);
    place_ships(1);

    int winner;
    do{
        queue = strike(queue) ? queue : (queue ? 0 : 1);
        winner = check_winner();
    }while(!winner);

    print_winner(winner);
    std::system("pause");
    return 0;
}
