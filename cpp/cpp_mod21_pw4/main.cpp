#include <iostream>
#include <conio.h>
#include <vector>
#include <ctime>
#include "usb_hid_keys.h"
#include "utf8_to_ascii.h"
#include <fstream>
#include <cstring>

struct pos_t{
    int x = 0;
    int y = 0;
};

struct personage_t{
    std::string name;
    int health = 0;
    int armor = 0;
    int damage = 0;
    pos_t pos = {0,0};
    pos_t prevPos = {0,0};
};
personage_t hero, enemies[5];

char field[20][20];

std::string message;

void init_field(char s[20][20]){
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++) s[i][j] = (char)250;//ascii symbol '·'
    }
}

void print_field() {
    std::string s[] = {
                           /*0-1-2-3-4-5-6-7-8-9-0-1-2-3-4-5-6-7-8-9*/
            {utf8_to_ascii("╔═══════════ Enemies vs Hero ═══════════╦══════════════ State personage ═══════════╗\n")},/* 0*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ Name                │Health│ Armor│Damage║\n")},/* 1*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║─────────────────────┼──────┼──────┼──────║\n")},/* 2*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                     │      │      │      ║\n")},/* 3*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                     │      │      │      ║\n")},/* 4*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                     │      │      │      ║\n")},/* 5*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                     │      │      │      ║\n")},/* 6*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                     │      │      │      ║\n")},/* 7*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                     │      │      │      ║\n")},/* 8*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·╠═══════════════ Control keys ═════════════╣\n")},/* 9*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ A - left                                 ║\n")},/*10*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ D - right                                ║\n")},/*11*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ W - forward                              ║\n")},/*12*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ S - backward                             ║\n")},/*13*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ F2 - save state game                     ║\n")},/*14*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ F4 - load saved game                     ║\n")},/*15*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║ Q - exit                                 ║\n")},/*16*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·╠═════════════════ Message ════════════════╣\n")},/*17*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                                          ║\n")},/*18*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                                          ║\n")},/*19*/
            {utf8_to_ascii("║· · · · · · · · · · · · · · · · · · · ·║                                          ║\n")},/*20*/
            {utf8_to_ascii("╚═══════════════════════════════════════╩══════════════════════════════════════════╝\n")}/*21*/
            };
    /*Clear main field*/
    init_field(field);
    /*position enemies on field*/
    for(auto & e : enemies){
        if(e.health > 0) {
            field[e.pos.y][e.pos.x] = 'E';
        }
    }
    /*position hero on field*/
    if(hero.health > 0) field[hero.pos.y][hero.pos.x] = 'P';
    /*main field*/
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            s[i + 1][2 * j + 1] = field[i][j];
        }
    }
    /*state hero*/
    char buf[6] = "";
    for(int j = 0; j < hero.name.length(); j++ ) s[3][42 + j] = hero.name[j];
    sprintf(buf,"%5d",hero.health);
    for(int j = 0; buf[j] != '\0'; j++ ) s[3][64 + j] = buf[j];
    sprintf(buf,"%5d",hero.armor);
    for(int j = 0; buf[j] != '\0'; j++ ) s[3][71 + j] = buf[j];
    sprintf(buf,"%5d",hero.damage);
    for(int j = 0; buf[j] != '\0'; j++ ) s[3][78 + j] = buf[j];
    /*state enemies*/
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < enemies[i].name.length(); j++ ) s[4 + i][42 + j] = enemies[i].name[j];
        sprintf(buf,"%5d",enemies[i].health);
        for(int j = 0; buf[j] != '\0'; j++ ) s[4 + i][64 + j] = buf[j];
        sprintf(buf,"%5d",enemies[i].armor);
        for(int j = 0; buf[j] != '\0'; j++ ) s[4 + i][71 + j] = buf[j];
        sprintf(buf,"%5d",enemies[i].damage);
        for(int j = 0; buf[j] != '\0'; j++ ) s[4 + i][78 + j] = buf[j];
    }
    /*message*/
    for(int j = 0; j < message.length(); j++ ) s[19][42 + j] = message[j];

    std::system("cls");
    int i = 0;
    for(const auto & e : s) std::cout << s[i++];
}

void init_hero(personage_t* h){
    std::cout << "Enter hero name:";
    std::cin >> h->name;
    std::cout << "Enter hero health:";
    std::cin >> h->health;
    std::cout << "Enter hero armor:";
    std::cin >> h->armor;
    std::cout << "Enter hero damage:";
    std::cin >> h->damage;
    h->prevPos.x = h->pos.x = std::abs(std::rand())%20;
    h->prevPos.y = h->pos.y = std::abs(std::rand())%20;;
}

void change_position_hero(personage_t* h, char cmd){
    h->prevPos.y = h->pos.y;
    h->prevPos.x = h->pos.x;
    if(cmd == 'a'){
        if(h->pos.x > 0) h->pos.x--;
    }
    else if(cmd == 'd'){
        if(h->pos.x < 19) h->pos.x++;
    }
    else if(cmd == 'w'){
        if(h->pos.y > 0) h->pos.y--;
    }
    else if(cmd == 's') {
        if(h->pos.y < 19) h->pos.y++;
    }

    /*if(field[h->pos.y][h->pos.x] == (char)250) {*//*If this position is free*//*
        field[h->prevPos.y][h->prevPos.x] = (char)250;
        field[h->pos.y][h->pos.x] = 'P';
    }
    else{*//*If this position is busy, coordinates not change*//*
        h->pos.x = h->prevPos.x;
        h->pos.y = h->prevPos.y;
    }*/
    if(field[h->pos.y][h->pos.x] != (char)250) {/*If this position on field is not free*/
        h->pos.x = h->prevPos.x;
        h->pos.y = h->prevPos.y;
    }
}

void init_enemies(personage_t* e){
    for(int i = 0; i < 5; i++){
        (e + i)->name = ("Enemy#" + std::to_string(i + 1));
        (e + i)->health = std::abs(std::rand())%101 + 50;
        (e + i)->armor = std::abs(std::rand())%51;
        (e + i)->damage = std::abs(std::rand())%16 + 15;
        (e + i)->pos.x = std::abs(std::rand())%20;
        (e + i)->pos.y = std::abs(std::rand())%20;
        (e + i)->prevPos.x = (e + i)->pos.x;
        (e + i)->prevPos.y = (e + i)->pos.y;
    }
}

void change_position_enemies(personage_t* e){
    for(int i = 0; i < 5; i++){
        if((e + i)->health > 0){
            (e + i)->prevPos.x = (e + i)->pos.x;
            (e + i)->prevPos.y = (e + i)->pos.y;
            (e + i)->pos.x += std::abs(std::rand())%3 - 1;
            (e + i)->pos.y += std::abs(std::rand())%3 - 1;
            if((e + i)->pos.x < 0)    (e + i)->pos.x = 0;
            if((e + i)->pos.x > 19)   (e + i)->pos.x = 19;
            if((e + i)->pos.y < 0)    (e + i)->pos.y = 0;
            if((e + i)->pos.y > 19)   (e + i)->pos.y = 19;

            if(field[(e + i)->pos.y][(e + i)->pos.x] != (char)250){/*If this position on field is not free*/
                (e + i)->pos.x = (e + i)->prevPos.x;
                (e + i)->pos.y = (e + i)->prevPos.y;
            }
        }
    }
}

int load_game(std::string &path, personage_t* h, personage_t* e, std::string* msg){
    std::ifstream gameState;
    gameState.open(path,std::ios::binary);
    if(!gameState.is_open()){
        *msg = "Fail loaded: ";
        *msg += strerror(errno);
        return errno;
    }
    else{
        gameState   >> h->name >> h->health >> h->armor >> h->damage
                    >> h->pos.x >> h->pos.y >> h->prevPos.x >> h->prevPos.y;

        for(int i = 0; i < 5; i++){
            gameState   >> (e + i)->name >> (e + i)->health >> (e + i)->armor
                        >> (e + i)->damage >> (e + i)->pos.x >> (e + i)->pos.y
                        >> (e + i)->prevPos.x >> (e + i)->prevPos.y;
        }
        *msg = "Game loaded from save";
    }
    gameState.close();
    return 0;
}

int save_game(std::string &path, personage_t* h, personage_t* e, std::string* msg){
    std::ofstream gameState;
    gameState.open(path,std::ios::binary);
    if(!gameState.is_open()){
        *msg = "Fail saved: ";
        *msg += strerror(errno);
        return errno;
    }
    else{
        gameState   << h->name << " " << h->health << " " << h->armor << " " << h->damage << " "
                    << h->pos.x << " " << h->pos.y << " " << h->prevPos.x << " " << h->prevPos.y << '\n';

        for(int i = 0; i < 5; i++){
            gameState   << (e + i)->name << " " << (e + i)->health << " " << (e + i)->armor << " "
                        << (e + i)->damage << " " << (e + i)->pos.x << " " << (e + i)->pos.y << " "
                        << (e + i)->prevPos.x << " " << (e + i)->prevPos.y << '\n';
        }
        *msg = "Game saved";
    }
    gameState.close();
    return 0;
}

void take_damage(personage_t* h, personage_t* e){
    h->armor -= e->damage;
    if(h->armor < 0){
        if(h->health > 0) h->health -= e->damage;
        if(h->health < 0) h->health = 0;
        h->armor = 0;
    }

    e->armor -= h->damage;
    if(e->armor < 0){
        if(e->health > 0) e->health -= h->damage;
        if(e->health < 0) e->health = 0;
        e->armor = 0;
    }
}

void check_the_fight(personage_t* h,personage_t* e, std::string* msg){
    for(int i = 0; i < 5; i++){
        if((e + i)->health > 0) {
            if (std::abs(h->pos.x - (e + i)->pos.x) == 1 && std::abs(h->pos.y - (e + i)->pos.y) == 0 ||
                std::abs(h->pos.x - (e + i)->pos.x) == 0 && std::abs(h->pos.y - (e + i)->pos.y) == 1) {
                take_damage(h, e + i);
                *msg = "Fight: " + h->name + " vs. " + (e + i)->name;
            }
        }
    }
}

void check_winner(personage_t* h,personage_t* e, std::string* msg){
    if(e->health == 0 && (e + 1)->health == 0 && (e + 2)->health == 0 &&
            (e + 3)->health == 0 && (e + 4)->health == 0){
        *msg = "Game over: Hero " + h->name + " won!";
        print_field();
        exit(0);
    }
    else if(h->health == 0){
        *msg = "Game over: Enemies won!";
        print_field();
        exit(0);
    }
}

int main() {

    std::string path = "../save.bin";

    std::srand(std::time(nullptr));

    init_hero(&hero);
    change_position_hero(&hero,'0');

    init_enemies(&enemies[0]);
    change_position_enemies(&enemies[0]);

    for(;;){
        print_field();

        while(!kbhit());
        char ch = (char)getch();

        if(ch == (uint8_t)KEY_F2){
            save_game(path,&hero,&enemies[0],&message);
        }
        else if(ch == (uint8_t)KEY_F4){
            load_game(path,&hero,&enemies[0],&message);
        }
        else if(ch == 'q') {
            exit(0);
        }
        else if(ch == 'a' || ch == 'w' || ch == 's' || ch == 'd'){
            change_position_hero(&hero,ch);
            change_position_enemies(&enemies[0]);
            check_the_fight(&hero,&enemies[0],&message);
            check_winner(&hero,&enemies[0],&message);
        }
    }
}
