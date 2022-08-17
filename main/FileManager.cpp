#include"FileManager.h"
#include<iostream>
#include<fstream>

int
FileManager::LoadFile(const char* path) 
{
    std::ifstream f;
    f.open(path);
    if (f.is_open()) {
        size_t i = 0;
        while (f) {
            st.resize(i + 1);
            getline(f, st[i]);
            ++i;
        }
        f.close();
    } else {
        return -1;
    }
    
    return 0;
}