#include <dirent.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
    DIR* dir = opendir(".");
    if(dir == NULL){
    return 1;
    }
    struct dirent* a;
    a = readdir(dir);
    while(a != NULL){
        cout<< a->d_name <<endl;
        a = readdir(dir);
    }
    closedir(dir);
    return 0;
}
