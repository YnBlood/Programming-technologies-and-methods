#include "BitStringDynamic.h"

BitString::BitString() {
    size = 9;
    bs = new char[size];

    for (int i = 0; i < 8; i++) {
        bs[i] = '0';
    }

    bs[8] = '\0';
}

BitString::BitString(string inp_string) {
    size = 9;
    bs = new char[size];

    for (int i = 0; i < 8; i++) {
        bs[i] = '0';
    }

    bs[8] = '\0';
    setString(inp_string);
}

BitString::BitString(const BitString& other) {
    size = other.size;
    bs = new char[size];

    for (int i = 0; i < size; i++) {
        bs[i] = other.bs[i];
    }
}

BitString::~BitString() {
    delete[] bs;
}

bool BitString::setString(string inp_string) {
    if (inp_string.length() > 8) {
        return false;
    }

    for (int i = 0; i < inp_string.length(); i++) {
        if (inp_string[i] != '0' && inp_string[i] != '1') {
            return false;
        }
    }

    for (int i = 0; i < 8; i++) {
        bs[i] = '0';
    }

    int j = 7;

    for (int i = inp_string.length() - 1; i >= 0; i--) {
        bs[j] = inp_string[i];
        j--;
    }

    bs[8] = '\0';
    return true;
}

bool BitString::fileInput(string filename, int num) {
    ifstream fin(filename);

    if (!fin.is_open()) {
        return false;
    }

    string inp_string;

    for (int i = 0; i < num; i++) {
        if (!(fin >> inp_string)) {
            fin.close();
            return false;
        }
    }

    fin.close();
    return setString(inp_string);
}

bool BitString::fileOutput(string filename, string text, bool append) {
    ofstream fout;

    if (append) {
        fout.open(filename, ios::app);
    } else {
        fout.open(filename);
    }

    if (!fout.is_open()) {
        return false;
    }

    fout << text;

    for (int i = 0; i < 8; i++) {
        fout << bs[i];
    }

    fout << endl;
    fout.close();
    return true;
}

void BitString::output() {
    for (int i = 0; i < 8; i++) {
        cout << bs[i];
    }

    cout << endl;
}

string BitString::getString() {
    string str = "";

    for (int i = 0; i < 8; i++) {
        str += bs[i];
    }

    return str;
}

BitString BitString::conjunction(BitString b) {
    char tmp[9];

    for (int i = 0; i < 8; i++) {
        if (bs[i] == '1' && b.bs[i] == '1') {
            tmp[i] = '1';
        } else {
            tmp[i] = '0';
        }
    }

    tmp[8] = '\0';
    return BitString(string(tmp));
}
