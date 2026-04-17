#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 9;

int getLen(char bs[]) {
    int len = 0;

    while (bs[len] != '\0') {
        len++;
    }

    return len;
}

bool checkLen(char bs[]) {
    if (getLen(bs) > 8) {
        return false;
    }

    return true;
}

bool checkStr(char bs[]) {
    int len = getLen(bs);

    for (int i = 0; i < len; i++) {
        if (bs[i] != '0' && bs[i] != '1') {
            return false;
        }
    }

    return true;
}

void makeNewStr(char bs[], int len) {
    for (int i = 7; i >= 0; i--) {
        if (len > 0) {
            bs[i] = bs[len - 1];
            len--;
        } else {
            bs[i] = '0';
        }
    }

    bs[8] = '\0';
}

void doAnd(char bs1[], char bs2[]) {
    for (int i = 0; i < 8; i++) {
        if (bs1[i] == '1' && bs2[i] == '1') {
            bs1[i] = '1';
        } else {
            bs1[i] = '0';
        }
    }
}

bool readFromFile(char bs1[], char bs2[]) {
    ifstream fin("input.txt");

    if (!fin.is_open()) {
        return false;
    }

    fin >> bs1;
    fin >> bs2;

    fin.close();
    return true;
}

bool writeToFile(char bs1[], char bs2[]) {
    ofstream fout("output.txt");

    if (!fout.is_open()) {
        return false;
    }

    fout << "Изменненная 1 строка: " << bs1 << endl;
    fout << "Изменненная 2 строка: " << bs2 << endl;
    fout << "Результат AND: " << bs1 << endl;

    fout.close();
    return true;
}

int main() {
    char bs1[SIZE];
    char bs2[SIZE];

    int lenA = 0;
    int lenB = 0;
    int way = 0;

    cout << "Выберите способ ввода:" << endl;
    cout << "1 - с консоли" << endl;
    cout << "2 - из файла" << endl;
    cin >> way;

    if (way == 1) {
        cout << "Введите первую битовую строку: ";
        cin >> bs1;

        cout << "Введите вторую битовую строку: ";
        cin >> bs2;
    } else if (way == 2) {
        if (!readFromFile(bs1, bs2)) {
            cout << "Ошибка, файл не открылся. " << endl;
            return 0;
        }

        cout << "Первая строка из файла: " << bs1 << endl;
        cout << "Вторая строка из файла: " << bs2 << endl;
    } else {
        cout << "Ошибка, неверный способ ввода. " << endl;
        return 0;
    }

    lenA = getLen(bs1);
    lenB = getLen(bs2);

    if (!checkLen(bs1) || !checkLen(bs2)) {
        cout << "Ошибка, длина строки больше 8 бит. " << endl;
        return 0;
    }

    if (!checkStr(bs1)) {
        cout << "Ошибка, первая строка введена неккоректно. " << endl;
        return 0;
    }

    if (!checkStr(bs2)) {
        cout << "Ошибка, вторая строка введена неккоректно. " << endl;
        return 0;
    }

    makeNewStr(bs1, lenA);
    cout << "Изменненная 1 строка: " << bs1 << endl;

    makeNewStr(bs2, lenB);
    cout << "Изменненная 2 строка: " << bs2 << endl;

    doAnd(bs1, bs2);

    cout << "Результат AND: " << bs1 << endl;

    if (writeToFile(bs1, bs2)) {
        cout << "Результат записан в файл. " << endl;
    } else {
        cout << "Ошибка, файл для записи не открылся. " << endl;
    }

    return 0;
}
