#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
using namespace std::filesystem;

void lines(){
    int licznik = 0;
    for(const directory_entry& entry : recursive_directory_iterator("/home/michal/zadanko/bcfsoftware")) {
        bool isNormalFile = is_regular_file(entry);
        auto path = entry.path();
        if(isNormalFile){
        licznik++;}
        string filenameString = path.filename().string();
        }
    cout<<"Number of files: "<<licznik<<endl;
}
int main() {
    lines();
    return 0;
}
