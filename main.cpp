#include <iostream>
#include <string>
#include <filesystem>
using namespace std;
using namespace std::filesystem;
int main() {
    for(const directory_entry& entry : recursive_directory_iterator("/home/michal/zadanko/bcfsoftware")) {

        bool isNormalFile = is_regular_file(entry);
        bool isDirectory = is_directory(entry);
        auto path = entry.path();

        string pathString = path.string();
        cout << pathString << endl;

        string filenameString = path.filename().string();

        string extensionString = path.extension().string();

    }
    return 0;
}
