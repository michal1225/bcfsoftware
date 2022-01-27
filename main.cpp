#include <iostream>
#include <string>
#include <filesystem>
#include <thread>
#include <fstream>
#include <vector>
using namespace std;
using namespace std::filesystem;

void files(){
    int licznik = 0;
    for(const directory_entry& entry : recursive_directory_iterator("/home/michal/")) {
        bool isNormalFile = is_regular_file(entry);
        auto path = entry.path();
        string pathString = path.string();
        if(isNormalFile){
        licznik++;
        }
    }
    cout<<"Number of files: "<<licznik<<endl;
}
vector<string> lista(){
    vector<string> arr;
    for(const directory_entry& entry : recursive_directory_iterator("/home/michal/")) {
        bool isNormalFile = is_regular_file(entry);
        auto path = entry.path();
        string pathString = path.string();
        if(isNormalFile){
            arr.push_back(pathString);
        }
    }
    return arr;
}
void lines(vector<string> mac){
    long line = 0;
    string linia;
    for (string b: mac){
        ifstream f;
        f.open(b);
        if(!f.is_open()){
            break;
            }
        else{
            while(getline(f, linia)){
                line++;
                }
            f.close();
            }
    }
    cout<<"Number of lines in files: "<<line<<endl;

}

int main() {
    thread pliki(files);
    thread maci(lista);
    vector<string> macierz = maci.join();
    long c = lines(macierz);
    cout<<c;

    return 0;
}
