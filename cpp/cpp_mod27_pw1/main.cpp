#include <iostream>
#include <ctime>

class Branch{

public:
    Branch* parent = nullptr;
    Branch* childs[5]{nullptr};
    int numberChilds{};
    std::string elfName = "None";

    Branch* search(std::string &name){
        Branch* temp = nullptr;
        if(elfName == name){
            temp = this;
        }
        else{
            for(int i = 0; i < numberChilds; i++){
                temp = childs[i]->search(name);
                if(temp != nullptr) break;
            }
        }
        return temp;
    }
};

class Forest{

    static const int NUMBER_OF_TREES = 5;
    Branch* trees[NUMBER_OF_TREES]{};

public:

    Forest(){
        for (int i = 0; i < NUMBER_OF_TREES; i++){
            trees[i] = new Branch;
            //trees[i]->parent = nullptr;
            trees[i]->numberChilds = std::rand()%3 + 3;//big branches (from 3 to 5)

            /*Create big branches for current wood*/
            Branch* bigBranch[trees[i]->numberChilds];
            for(int j = 0; j < trees[i]->numberChilds; j++){
                bigBranch[j] = new Branch;
                trees[i]->childs[j] = bigBranch[j];
                bigBranch[j]->parent = trees[i];
                bigBranch[j]->numberChilds = std::rand()%2 + 2;// middle branches (from 2 to 3)

                /*Create middle branches for current big branch*/
                Branch* middleBranch[bigBranch[j]->numberChilds];
                for(int k = 0; k < bigBranch[j]->numberChilds; k++){
                    middleBranch[k] = new Branch;
                    bigBranch[j]->childs[k] = middleBranch[k];
                    middleBranch[k]->parent = bigBranch[j];
                    middleBranch[k]->numberChilds = 0;
                }
            }
        }
    }

    void show(){
        for(int i = 0; i < NUMBER_OF_TREES; i++){
            std::cout   << "-> tree " << i << ":"
                        //<<": ptr=" << trees[i]
                        << " childs=" << trees[i]->numberChilds
                        << std::endl;
            for(int j = 0; j < trees[i]->numberChilds; j++){
                std::cout << "   --> bigBranch " << j << ":"
                          //<<": ptr=" << trees[i]->childs[j]
                          << " childs=" << trees[i]->childs[j]->numberChilds
                          << " elfName=" << trees[i]->childs[j]->elfName
                          << std::endl;
                for(int k = 0; k < trees[i]->childs[j]->numberChilds; k++){
                    std::cout << "      ---> middleBranch " << k << ":"
                              //<<": ptr=" << trees[i]->childs[j]->childs[k]
                              << " childs=" << trees[i]->childs[j]->childs[k]->numberChilds
                              << " elfName=" << trees[i]->childs[j]->childs[k]->elfName
                              << std::endl;
                }
            }
        }
    }

    void elf_settle(){
        std::cout << "Start elf's settlement:" << std::endl;
        std::string n;
        for(int i = 0; i < NUMBER_OF_TREES; i++){
            for(int j = 0; j < trees[i]->numberChilds; j++){
                std::cout << "[" << i << ":" << j << "]" << "Enter elf name:";
                std::cin >> n;
                if(n != "None") trees[i]->childs[j]->elfName = n;
                for(int k = 0; k < trees[i]->childs[j]->numberChilds; k++){
                    std::cout << "[" << i << ":" << j << ":" << k << "]" << "Enter elf name:";
                    std::cin >> n;
                    if(n != "None") trees[i]->childs[j]->childs[k]->elfName = n;
                }
            }
        }
    }

    void search_neighbours(){
        std::cout << "Enter name of elf to search:";
        std::string elf;
        std::cin >> elf;
        Branch* elfptr;
        for(auto & tree : trees){
            elfptr = tree->search(elf);
            if(elfptr != nullptr) break;
        }

        int neighbours{};

        if(elfptr != nullptr){
            if(elfptr->parent->parent == nullptr){/*big branch*/
                if(elfptr->elfName != "None")
                    neighbours += 1;
                for(int i = 0; i < elfptr->numberChilds; i++)
                    if(elfptr->childs[i]->elfName != "None")
                        neighbours += 1;
            }
            else{/*middle branch*/
                if(elfptr->parent->elfName != "None")
                    neighbours += 1;
                for(int i = 0; i < elfptr->parent->numberChilds; i++)
                    if(elfptr->parent->childs[i]->elfName != "None")
                        neighbours += 1;
            }
            std::cout << "Number of neighbours: " << neighbours;
        }
        else{
            std::cout << "There is no such elf in the forest!" << std::endl;
        }
    }

};

int main() {

    std::srand(std::time(nullptr));

    auto forest = new Forest;

    //forest->show();

    forest->elf_settle();

    //forest->show();

    forest->search_neighbours();

    delete forest;
    return 0;
}
