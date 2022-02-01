#include <iostream>
#include <string>
#include <filesystem>
#include <thread>
#include <fstream>
#include <vector>
#include <gtest/gtest.h>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::filesystem;
using namespace chrono;
void files(){
    auto start = high_resolution_clock::now();
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
        auto stop = high_resolution_clock::now();
        cout <<"Count files time(s): "<<duration_cast<seconds>(stop - start).count() << '\n';
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
    auto start = high_resolution_clock::now();
    long line = 0;
    string linia;
    for (string b: mac){
        ifstream f;
        f.open(b);
        if(!f.is_open()){
            ;
        }
    else{
        while(getline(f, linia)){
            line++;
            }
        f.close();
        }
    }
    cout<<"Number of lines in files: "<<line<<endl;
    auto stop = high_resolution_clock::now();
    cout <<"Count lines time(s): "<<duration_cast<seconds>(stop - start).count() << '\n';
}
void letters(vector<string> mac){
    auto start = high_resolution_clock::now();
    long long letter = 0;
    string linia;
    for (string b: mac){
        ifstream f;
        f.open(b);
        if(!f.is_open()){
            ;
        }
    else{
        while(getline(f, linia)){
            letter = letter + linia.length();
            }
        f.close();
        }
    }
    cout<<"Number of letters in files: "<<letter<<endl;
    auto stop = high_resolution_clock::now();
    cout <<"Count letters time(s): "<<duration_cast<seconds>(stop - start).count() << '\n';
}
void words(vector<string> mac){
    auto start = high_resolution_clock::now();
    long long word = 0;
    string linia;
    for (string b: mac){
        ifstream f;
        f.open(b);
        if(!f.is_open()){
            ;
        }
    else{
        while(getline(f, linia)){
            stringstream lineStream(linia);
            while(getline(lineStream, linia, ' '))
            {
                word++;
            };
            }
        f.close();
        }
    }
    cout<<"Number of words in files: "<<word<<endl;
    auto stop = high_resolution_clock::now();
    cout <<"Count words time(s): "<<duration_cast<seconds>(stop - start).count() << '\n';
}

int main() {
    vector<string> macierz = lista();
    thread Thread1(files);
    thread Thread2(lines, macierz);
    thread Thread3(letters, macierz);
    thread Thread4(words, macierz);
    Thread2.join();
    Thread1.join();
    Thread3.join();
    Thread4.join();
    return 0;
}
