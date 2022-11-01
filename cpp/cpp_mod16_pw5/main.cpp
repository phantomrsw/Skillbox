#include <iostream>
#include <sstream>

enum switches
{
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16
};
int switches_state;

std::string sLogs[12];
int ptrLogs;

int hours = 0;
int colorLight = 0;

typedef struct{
    int tempInside;
    int tempOutside;
    int motion;
    int light;
}sensors;

sensors sens = {0, 0, 0, 0};

void switch_on(int pos){switches_state |= pos;}

void switch_off(int pos){switches_state &= ~pos;}

bool parsingInput(std::string &s){
    std::stringstream bufs(s);
    std::string str[4];
    bufs >> str[0] >> str[1] >> str[2] >> str[3];

    if(str[0][0] != '-' && (str[0][0] < '0' || str[0][0] > '9')) return false;
    else for(int i = 1; i < str[0].length(); i++) if(str[0][i] < '0' || str[0][i] > '9') return false;
    sens.tempInside = std::stoi(str[0]);

    if(str[1][0] != '-' && (str[1][0] < '0' || str[1][0] > '9')) return false;
    else for(int i = 1; i < str[1].length(); i++) if(str[1][i] < '0' || str[1][i] > '9') return false;
    sens.tempOutside = std::stoi(str[1]);

    if(str[2] != "yes" && str[2] != "no" ) return false;
    else sens.motion = ((str[2] == "yes") ? 1 : 0);

    if(str[3] != "on" && str[3] != "off" ) return false;
    else sens.light = ((str[3] == "on") ? 1 : 0);

    return  true;
}

void print_screen(){
    std::string s[] = {
            {"+===============Logs=================+======State sensors=======+\n"},
            {"|                                    |Temperature inside:       |\n"},
            {"|                                    |Temperature outside:      |\n"},
            {"|                                    |Motion:                   |\n"},
            {"|                                    |Light:                    |\n"},
            {"|                                    +======State switches======|\n"},
            {"|                                    |Light inside:             |\n"},
            {"|                                    |Light outside:            |\n"},
            {"|                                    |Heaters:                  |\n"},
            {"|                                    |Water pipe heating:       |\n"},
            {"|                                    |Conditioner:              |\n"},
            {"|                                    +========Color light=======|\n"},
            {"|                                    |Color Light:              |\n"},
            {"+====================================+==========================+\n"}};
    /*State sensors*/
    char buf[6] = "";
    sprintf(buf,"%3d",sens.tempInside);
    for(int j = 0; buf[j] != '\0'; j++ ) s[1][59 + j] = buf[j];
    sprintf(buf,"%3d",sens.tempOutside);
    for(int j = 0; buf[j] != '\0'; j++ ) s[2][59 + j] = buf[j];
    sprintf(buf,"%3s",(sens.motion ? "yes" : "no"));
    for(int j = 0; buf[j] != '\0'; j++ ) s[3][59 + j] = buf[j];
    sprintf(buf,"%3s",(sens.light ? "on" : "off"));
    for(int j = 0; buf[j] != '\0'; j++ ) s[4][59 + j] = buf[j];
    /*State switches*/
    for(int i = 0; i < 5; i++){
        sprintf(buf,"%3s",(switches_state & (1 << i) ? "on" : "off"));
        for(int j = 0; buf[j] != '\0'; j++ ) s[i + 6][59 + j] = buf[j];
    }
    /*Color light*/
    sprintf(buf,"%3d",colorLight);
    for(int j = 0; buf[j] != '\0'; j++ ) s[12][59 + j] = buf[j];
    /*Logs*/
    for(int i = 0; i < 12; i++){
        for(int j = 0; sLogs[i][j] != '\0'; j++){
            s[i + 1][j + 1] = sLogs[i][j];
        }
    }

    std::system("cls");
    int i = 0;
    for(const auto & e : s) std::cout << s[i++];
}

void control(sensors &sns){
    if(sns.tempInside >= 30) switch_on(CONDITIONER);
    else if(sns.tempInside <= 25) switch_off(CONDITIONER);

    if(sns.tempInside >= 25) switch_off(HEATERS);
    else if(sns.tempInside < 22) switch_on(HEATERS);

    if(sns.tempOutside < 0) switch_on(WATER_PIPE_HEATING);
    else if(sns.tempOutside > 5) switch_off(WATER_PIPE_HEATING);

    if((hours > 16 || hours < 5) && sns.motion == 1) switch_on(LIGHTS_OUTSIDE);
    else switch_off(LIGHTS_OUTSIDE);

    if(sns.light ==1){
        switch_on(LIGHTS_INSIDE);
        if(hours >= 0 && hours < 16) colorLight = 5000;
        else if(hours >= 16 && hours <=20)
            colorLight = 5000 - (std::abs(16 - hours))*((5000 - 2700)/(20-16));
    }
    else {
        switch_off(LIGHTS_INSIDE);
        colorLight = 0;
    }
}

void saveLogs(std::string &s){
    if(ptrLogs != 12){
        for(int i = 0; s[i] != '\0'; i++) sLogs[ptrLogs][i] = s[i];
        ptrLogs++;
    }
    else{
        for(int i = 0; i < 11; i++) {
            int j = 0;
            for(; sLogs[i + 1][j] != '\0'; j++) {
                sLogs[i][j] = sLogs[i + 1][j];
            }
            sLogs[i][j] = '\0';
        }
        for(int i = 0; i <= s.length(); i++) sLogs[11][i] = s[i];
    }
}

int main() {

    int day = 1;
    std::string sIn;

    do{
        print_screen();

        std::cout << "[day:" << day << " time:" << hours <<":00]Enter state sensors:";
        std::getline(std::cin, sIn);

        while(!parsingInput(sIn)){
            std::cout << "Input incorrect! Enter again:";
            std::getline(std::cin, sIn);
        }

        saveLogs(sIn);

        control(sens);

        if(hours == 23) {
            hours = 0;
            day++;
        }
        else hours++;
    }while(day < 3);

    std::system("pause");
    return 0;
}
