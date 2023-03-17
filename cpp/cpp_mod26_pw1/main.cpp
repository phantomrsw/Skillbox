#include <iostream>
#include <vector>
#include <iomanip>

class Track{
public:
    std::string title{};
    std::tm createDate{};
    int duration{};
};

class Player{
    enum state_t {PLAY,PAUSE,STOP} state = STOP;
    int currTrack{};
    std::vector<Track> tracks;

public:

    std::string get_command(std::istream* cin){
        std::cout << "Enter command:";
        std::string s{};
        *(cin) >> s;
        return s;
    }

    void add_track(const std::string &newTitle, const std::string& newCreateDate, int newDuration){
        Track newTrack{};

        newTrack.title = newTitle;
        (std::stringstream) newCreateDate >> std::get_time(&newTrack.createDate, "%d.%m.%Y");
        newTrack.duration = newDuration;

        tracks.push_back(newTrack);
    }

    void display_track_list(){
        std::cout << "Track list:" << std::endl;
        for(auto & track : tracks){
            std::cout   << track.title << " "
                        << std::put_time(&track.createDate, "%d.%m.%Y") << " "
                        << track.duration << std::endl;
        }
    }

    void display_curr_track(){
        std::cout   << "Play track: " << tracks[currTrack].title << " "
                    << "(Create date: " << std::put_time(&(tracks[currTrack].createDate), "%d.%m.%Y") << "; "
                    << "Duration: " << tracks[currTrack].duration << " sec.)"<< std::endl;
    }

    void play(){
        if(state != PLAY) {
            if(state != PAUSE){
                std::cout << "Enter track title:";
                std::string title;
                std::cin >> title;
                for(int i = 0;  i < tracks.size(); i++){
                    if(tracks[i].title == title){
                        currTrack = i;
                        break;
                    }
                    if((i + 1) == tracks.size()){
                        std::cout << "Track not found!" << std::endl;
                        return;
                    }
                }
            }
            display_curr_track();
            state = PLAY;
        }
    }
    void pause(){
        if(state == PLAY){
            std::cout << "The track is paused." << std::endl;
            state = PAUSE;
        }
    }
    void stop(){
        if(state != STOP){
            std::cout << "Playback is stopped." << std::endl;
            state = STOP;
        }
    }
    void next(){
        std::srand(std::time(nullptr));
        currTrack = std::rand()%tracks.size();
        if(state == PLAY) display_curr_track();
    }
};



int main() {
    std::cout << std::string(29,'=') << std::endl;
    std::cout << "AudioPlayer emulation program" << std::endl;
    std::cout << std::string(29,'=') << std::endl;

    Player player;

    player.add_track("Track1","01.02.2023",240);
    player.add_track("Track2","02.02.2023",250);
    player.add_track("Track3","03.02.2023",260);
    player.add_track("Track4","04.02.2023",270);
    player.add_track("Track5","05.02.2023",280);

    std::string cmd;

    for(;;){

        cmd = player.get_command(&std::cin);

        if(cmd == "exit"){
            exit(0);
        }
        else if(cmd == "play"){
            player.play();
        }
        else if(cmd == "pause"){
            player.pause();
        }
        else if(cmd == "stop"){
            player.stop();
        }
        else if(cmd == "next"){
            player.next();
        }
        else if(cmd == "list"){
            player.display_track_list();
        }
        else{
            std::cout << "Unknown command!" << std::endl;
        }
    }

}
