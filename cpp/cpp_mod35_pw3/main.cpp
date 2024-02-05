#include <iostream>
#include <filesystem>
#include <vector>

int main() {

    auto recursiveGetFileNamesByExtension =
            [](std::filesystem::path path, const std::string extension){

        std::vector<std::string> list;

        for(auto& p: std::filesystem::recursive_directory_iterator(path)){
            if(p.is_regular_file()){
                if(!(p.path().extension().compare(extension))){
                    list.push_back(p.path().filename().string());
                }
            }
        }
        return list;
    };

    std::filesystem::path path{"."};
    std::string extension{".txt"};

    auto list = recursiveGetFileNamesByExtension(path, extension);

    std::cout << "Found \"" << extension << "\" files in path \""<< path <<"\" :" << std::endl;
    for(auto & l : list)
        std::cout << l << std::endl;

    return 0;
}
