#include <iostream>
#include <fstream>
#include <vector>

int scoreExperts = 0, scoreViewers = 0;
int curSector = 0;
std::vector<int> prevSectors;

std::string pathQuestions[13] = {
        "../qa/qs1.txt",
        "../qa/qs2.txt",
        "../qa/qs3.txt",
        "../qa/qs4.txt",
        "../qa/qs5.txt",
        "../qa/qs6.txt",
        "../qa/qs7.txt",
        "../qa/qs8.txt",
        "../qa/qs9.txt",
        "../qa/qs10.txt",
        "../qa/qs11.txt",
        "../qa/qs12.txt",
        "../qa/qs13.txt"};

std::string pathAnswer[13] = {
        "../qa/as1.txt",
        "../qa/as2.txt",
        "../qa/as3.txt",
        "../qa/as4.txt",
        "../qa/as5.txt",
        "../qa/as6.txt",
        "../qa/as7.txt",
        "../qa/as8.txt",
        "../qa/as9.txt",
        "../qa/as10.txt",
        "../qa/as11.txt",
        "../qa/as12.txt",
        "../qa/as13.txt"};

bool usedSectors[13] = {false,false,false,false,false,false,
                        false,false,false,false,false,false,false,};

bool check_winner(int scoreE, int scoreV){
    if(scoreE == 6) {
        std::cout << "Experts win! Game over!";
        return true;
    }
    else if(scoreV == 6){
        std::cout << "Viewers win! Game over!";
        return true;
    }
    return false;
}

std::string get_question_answer(int sector,  const std::string& key){

    std::string s;
    std::ifstream file;
    if(key == "question") file.open(pathQuestions[sector]);
    if(key == "answer") file.open(pathAnswer[sector]);

    if(!file.is_open()) {
        std::cout << "Fail! File with question/answer for sector" << sector + 1 << "not exist!";
        exit(1);
    }

    std::getline(file, s);

    file.close();

    return s;
}

void print_info(){
    std::system("cls");
    std::cout << "=================================" << std::endl;
    std::cout << "=    What? Where? When? Game    =" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << "Used sectors:";
    for(auto e : prevSectors) std::cout << e << " ";
    std::cout << std::endl;
    std::cout << "Score Experts:" << scoreExperts << std::endl;
    std::cout << "Score Viewers:" << scoreViewers << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

int main() {

    print_info();

    while(!check_winner(scoreExperts,scoreViewers)){

        int offset;
        std::cout << "Enter offset:";
        std::cin >> offset;
        while(offset < 0){
            std::cout << "Offset cannot be negative! Enter offset again:";
            std::cin >> offset;
        }

        curSector += (offset % 13);
        if(curSector > 12) curSector -= 13;
        while(usedSectors[curSector]){
            curSector++;
            if(curSector == 13) curSector = 0;
        }
        usedSectors[curSector] = true;

        std::cout << "Current sector:" << curSector + 1 << std::endl;
        std::cout << "Question:" << get_question_answer(curSector,"question") << std::endl;

        std::string answer;
        std::cout << "Your answer:";
        std::cin >> answer;

        if(answer == get_question_answer(curSector,"answer")) {
            std::cout << "This is the correct answer! Congratulations!" << std::endl;
            scoreExperts++;
        }
        else {
            std::cout << "This is the incorrect answer! (Correct answer:"
                        << get_question_answer(curSector,"answer") << ")"<< std::endl;
            scoreViewers++;
        }

        std::system("pause");

        prevSectors.push_back(curSector + 1);
        print_info();
    }
    return 0;
}
