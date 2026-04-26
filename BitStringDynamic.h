#pragma once 
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BitString {
private:
    char* bs;
    int size;

public:
    BitString();
    BitString(string inp_string);
    BitString(const BitString& other);
    ~BitString();

    bool setString(string inp_string);
    bool fileInput(string filename, int num);
    bool fileOutput(string filename, string text, bool append);
    void output();
    string getString();
    BitString conjunction(BitString b);
};
