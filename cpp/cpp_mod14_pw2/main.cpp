#include <iostream>
#include <cassert>

char get_ascii_by_third_byte_utf8(int n){
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

std::string utf8_to_ascii(std::string s){
    std::string sOut;

    uint8_t sLength = s.length();
    for(int i = 0; i < sLength; i++){
        if(((uint8_t)s[i]) == 226 && ((uint8_t)s[i + 1]) == 149){
            sOut += get_ascii_by_third_byte_utf8((uint8_t)s[i + 2]);
            i += 2;
        }
        else sOut += s[i];

    }
    return sOut;
}

/*void sound_ascii(){std::cout << (char)7;}*/

void print_field(char f[3][3]){
    std::string s[8] = {{"         col     \n"},
                        {"    ╔═0═╦═1═╦═2═╗\n"},
                        {"    0   ║   ║   ║\n"},
                        {"    ╠═══╬═══╬═══╣\n"},
                        {"row 1   ║   ║   ║\n"},
                        {"    ╠═══╬═══╬═══╣\n"},
                        {"    2   ║   ║   ║\n"},
                        {"    ╚═══╩═══╩═══╝\n"}};
    for(int i = 0; i < 3; i++){
        for(int y = 0; y < 3; y++) {
            s[2 * i + 2] [6 * y + 6] = f[i][y];
        }
    }

    int i = 0;
    for(const auto & e : s)
        std::cout << utf8_to_ascii(s[i++]);
}

std::string getLine(char field[3][3], int n){
    std::string result;
    for(int i = 0; i < 3; i++) result += field[n][i];
    return result;
}

std::string getColumn(char field[3][3], int n){
    std::string result;
    for(int i = 0; i < 3; i++) result += field[i][n];
    return result;
}

std::string getDiagonal(char field[3][3], int n){
    std::string result;
    for(int i = 0; i < 3; i++) {
        if(n == 0) result += field[i][i];
        else result += field[2 - i][i];
    }
    return result;
}

std::string findWinner(char field[3][3]){
    std::string result;
    /*Search winner in rows*/
    for(int i = 0; i < 3; i++) {
        if(getLine(field,i) == "XXX") result += 'X';
        else if(getLine(field,i) == "OOO") result += 'O';
    }
    if(result.length()) return result;
    else result.clear();
    assert(result.empty());

    /*Search winner in columns*/
    for(int i = 0; i < 3; i++) {
        if (getColumn(field, i) == "XXX") result += 'X';
        else if (getColumn(field, i) == "OOO") result += 'O';
    }
    if(result.length()) return result;
    else result.clear();
    assert(result.empty());

    /*Search winner in diagonals*/
    for(int i = 0; i < 2; i++){
        if (getDiagonal(field, i) == "XXX") result += 'X';
        else if (getDiagonal(field, i) == "OOO") result += 'O';
    }
    return result;
}


int main() {
    std::cout   << utf8_to_ascii("╔═══════════════════════════════════╗") << "\n"
                << utf8_to_ascii("║         TIC-TAC-TOE GAME          ║") << "\n"
                << utf8_to_ascii("╚═══════════════════════════════════╝") << std::endl;

    char field[3][3] = {{' ',' ',' '},
                        {' ',' ',' '},
                        {' ',' ',' '}};

    bool places[3][3] = {{false,false,false},
                         {false,false,false},
                         {false,false,false}};
    int r, c;
    bool gameOver = false;
    int queue = 0, crosses = 0, zeros = 0;

    print_field(field);
    //sound_ascii();
    while(!gameOver){
        if(!queue) std::cout << "First (X) player, enter coordinate (row,col):";
        else std::cout << "Second (O) player, enter coordinate (row,col):";

        do{
            std::cin >> r >> c;
            if ((r < 0 || r > 2) || (c < 0 || c > 2))
                std::cout << "Incorrect value row or col! Enter again:";
            else if (places[r][c])
                std::cout << "This position is busy! Enter again:";
            else break;
        }while(true);

        if(!queue){
            field[r][c] = 'X';
            crosses++;
        }
        else{
            field[r][c] = 'O';
            zeros++;
        }
        places[r][c] = true;

        queue = ~queue;

        print_field(field);

        std::string winner = findWinner(field);

        if((winner == "XO" || winner == "OX") && crosses == zeros ||
                (crosses == 5 && zeros == 4)){
            std::cout << "Nobody won!" << std::endl;
            gameOver = true;
        }
        else if(winner == "X" && crosses == zeros){
            std::cout << "First player wins!" << std::endl;
            gameOver = true;
        }
        else if(winner == "O" && crosses == zeros){
            std::cout << "Second Player wins!" << std::endl;
            gameOver = true;
        }
    }

    std::cout   << utf8_to_ascii("╔═══════════════════════════════════╗") << "\n"
                << utf8_to_ascii("║             GAME OVER!            ║") << "\n"
                << utf8_to_ascii("╚═══════════════════════════════════╝") << std::endl;
    system("pause");
    return 0;
}
