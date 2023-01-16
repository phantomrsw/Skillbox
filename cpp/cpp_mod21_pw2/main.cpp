#include <iostream>
#include <vector>

enum room_type{
    CHILDREN_ROOM,
    BED_ROOM,
    LIVING_ROOM,
    BATH_ROOM,
    TOILET_ROOM
};
enum build_type{
    HOUSE_BUILD,
    GARAGE_BUILD,
    BARN_BUILD,
    VAPORARIUM_BUILD
};

struct desc_room_t{
    room_type type = TOILET_ROOM;
    int area = 1;
};

struct desc_floor_t{
    float ceilingHeight = 0;
    int numberRooms = 0;
    std::vector<desc_room_t> rooms;
};

struct desc_build_t{
    build_type type = HOUSE_BUILD;
    int area = 0;
    int numberFloors = 1;
    std::vector<desc_floor_t> floors;
    bool stove = false;
};

struct desc_homestead_t{
    std::vector<int> uniqueNumber;
    int numberBuilds = 0;
    std::vector<desc_build_t> builds;
};

int get_total_homesteads(std::vector<desc_homestead_t>* h);
int get_total_builds(std::vector<desc_homestead_t>* h);
int get_number_builds_of_type(std::vector<desc_homestead_t>* h, build_type b);
int get_total_rooms(std::vector<desc_homestead_t>* h);
int get_number_rooms_of_type(std::vector<desc_homestead_t>* h, room_type r);

int main() {


    int n;
    std::cout << "Enter the total number of homesteads (from 1 to 100):";
    std::cin >> n;
    while(n < 0 || n > 100){
        std::cout << "Incorrect input! Enter again:";
        std::cin >> n;
    }
    std::vector<desc_homestead_t> homesteads(n);

    for(int i = 0; i < homesteads.size(); i++){
        homesteads[i].uniqueNumber.push_back(i);
        std::cout << "How many buildings does the homestead " << i + 1 << " contain:";
        std::cin >> homesteads[i].numberBuilds;
        homesteads[i].builds.resize(homesteads[i].numberBuilds);

        for(int j = 0; j < homesteads[i].numberBuilds; j++){
            std::cout   << "What type of building " << j + 1 <<" ("
                        << HOUSE_BUILD << " - house, "
                        << GARAGE_BUILD << " - garage, "
                        << BARN_BUILD << " - barn, "
                        << VAPORARIUM_BUILD << " - vaporarium):";
            int type;
            std::cin >> type;
            while(type < HOUSE_BUILD || type > VAPORARIUM_BUILD){
                std::cout << "Incorrect input! Enter again:";
                std::cin >> type;
            }
            homesteads[i].builds[j].type = (build_type)type;

            int area;
            std::cout << "What is the area of this building on the homestead?:";
            std::cin >> area;
            while(area <= 0){
                std::cout << "Incorrect input! Enter again:";
                std::cin >> area;
            }
            homesteads[i].builds[j].area = area;

            if(homesteads[i].builds[j].type == HOUSE_BUILD || homesteads[i].builds[j].type == VAPORARIUM_BUILD){
                std::cout << "Does this building have a stove? (yes/no):";
                std::string answer;
                std::cin >> answer;
                if(answer == "yes") homesteads[i].builds[j].stove = true;
            }

            if(homesteads[i].builds[j].type == HOUSE_BUILD){
                std::cout << "How many floors are in the house (from 1 to 3)?:";
                int floors;
                std::cin >> floors;
                while(floors < 1 || floors >3){
                    std::cout << "Incorrect input! Enter again:";
                    std::cin >> floors;
                }
                homesteads[i].builds[j].numberFloors = floors;
                homesteads[i].builds[j].floors.resize(floors);

                for(int k = 0; k < floors; k++){
                    std::cout << "What is the height of the ceiling on the " << k + 1 << " floor(form 2.5 to 5.0 m)?:";
                    float height;
                    std::cin >> height;
                    while(height < 2.5f || height > 5.0f){
                        std::cout << "Incorrect input! Enter again:";
                        std::cin >> height;
                    }
                    homesteads[i].builds[j].floors[k].ceilingHeight = height;

                    std::cout << "How many rooms on the " << k + 1 << " floor?:";
                    int rooms;
                    std::cin >> rooms;
                    while(rooms < 2 || rooms > 4){
                        std::cout << "Incorrect input! Enter again:";
                        std::cin >> rooms;
                    }
                    homesteads[i].builds[j].floors[k].numberRooms = rooms;
                    homesteads[i].builds[j].floors[k].rooms.resize(rooms);

                    for(int l = 0; l < rooms; l++){
                        std::cout   << "What type of room " << l + 1 <<" ("
                                    << CHILDREN_ROOM << " - children room, "
                                    << BED_ROOM << " - bedroom, "
                                    << LIVING_ROOM << " - living room, "
                                    << BATH_ROOM    << " - bath room, "
                                    << TOILET_ROOM << " - toilet):";

                        //int type;
                        std::cin >> type;
                        while(type < CHILDREN_ROOM || type > TOILET_ROOM){
                            std::cout << "Incorrect input! Enter again:";
                            std::cin >> type;
                        }
                        homesteads[i].builds[j].floors[k].rooms[l].type = (room_type)type;

                        //int area;
                        std::cout << "What is the area of this room?:";
                        std::cin >> area;
                        while(area <= 0){
                            std::cout << "Incorrect input! Enter again:";
                            std::cin >> area;
                        }
                        homesteads[i].builds[j].floors[k].rooms[l].area = area;
                    }
                }
            }
        }
    }

    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "Summary information:"     << std::endl;
    std::cout << "\t- total homesteads:"    << get_total_homesteads(&homesteads)    << std::endl;
    std::cout << "\t- total builds:"        << get_total_builds(&homesteads)        << std::endl;
    std::cout << "\t\t- number of house:"      << get_number_builds_of_type(&homesteads,HOUSE_BUILD)      << std::endl;
    std::cout << "\t\t- number of garage:"     << get_number_builds_of_type(&homesteads,GARAGE_BUILD)     << std::endl;
    std::cout << "\t\t- number of barn:"       << get_number_builds_of_type(&homesteads,BARN_BUILD)       << std::endl;
    std::cout << "\t\t- number of vaporarium:" << get_number_builds_of_type(&homesteads,VAPORARIUM_BUILD) << std::endl;
    std::cout << "\t- total rooms:"          << get_total_rooms(&homesteads)        << std::endl;
    std::cout << "\t\t- number of children:" << get_number_rooms_of_type(&homesteads,CHILDREN_ROOM) << std::endl;
    std::cout << "\t\t- number of bath:"     << get_number_rooms_of_type(&homesteads,BATH_ROOM) << std::endl;
    std::cout << "\t\t- number of living:"   << get_number_rooms_of_type(&homesteads,LIVING_ROOM) << std::endl;
    std::cout << "\t\t- number of bedroom:"  << get_number_rooms_of_type(&homesteads,BED_ROOM) << std::endl;
    std::cout << "\t\t- number of toilets:"  << get_number_rooms_of_type(&homesteads,TOILET_ROOM) << std::endl;


    return 0;
}

int get_total_homesteads(std::vector<desc_homestead_t>* h){
    return (int)(h->size());
}

int get_total_builds(std::vector<desc_homestead_t>* h){
    int n = 0;
    for(auto & homestead : *h) n += homestead.numberBuilds;
    return n;
}

int get_number_builds_of_type(std::vector<desc_homestead_t>* h, build_type b){
    int n = 0;
    for(auto & homestead : *h) {
        for(auto & build : homestead.builds) if(build.type == b) n++;
    }
    return n;
}

int get_total_rooms(std::vector<desc_homestead_t>* h){
    int n = 0;
    for(auto & hs : *h)
        for(auto & bd : hs.builds)
            for(auto & fl : bd.floors)
                n += fl.numberRooms;
    return n;
}

int get_number_rooms_of_type(std::vector<desc_homestead_t>* h, room_type r){
    int n = 0;
    for(auto & hs : *h)
        for(auto & bd : hs.builds)
            for(auto & fl : bd.floors)
                for(auto & rm : fl.rooms)
                    if(rm.type == r) n++;
    return n;
}
