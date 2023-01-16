//
// Created by Partos on 08.12.2022.
//
#include <iostream>
#include "utf8_to_ascii.h"


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