#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class BitString {
private:
    char bs[9];

public:
    BitString();
    BitString(string inp_string);

    bool setString(string inp_string);
    bool fileInput(string filename, int num);
    bool fileOutput(string filename, string text, bool append);
    void output();
    BitString conjunction(BitString b);
};
