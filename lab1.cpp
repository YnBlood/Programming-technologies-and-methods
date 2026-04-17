#include <iostream>

using namespace std;

int main() {
    char bs1[9];
    char bs2[9];

    int lenA = 0;
    int lenB = 0;

    cout << "Введите первую битовую строку: ";
    cin >> bs1;

    cout << "Введите вторую битовую строку: ";
    cin >> bs2;

    while (bs1[lenA] != '\0') {
        lenA++;
    }
    while (bs2[lenB] != '\0') {
        lenB++;
    }

    if (lenA > 8 || lenB > 8) {
        cout << "Ошибка, длина строки больше 8 бит. " << endl;
        return 0;
    }

    for (int i = 0; i < lenA; i++) {
        if (bs1[i] != '0' && bs1[i] != '1') {
            cout << "Ошибка, первая строка введена неккоректно. " << endl;
            return 0;
        }
    }

    for (int i = 0; i < lenB; i++) {
        if (bs2[i] != '0' && bs2[i] != '1') {
            cout << "Ошибка, вторая строка введена неккоректно. " << endl;
            return 0;
        }
    }

    for (int i = 7; i >= 0; i--) {
        if (lenA > 0) {
            bs1[i] = bs1[lenA - 1];
            lenA--;
        } else {
            bs1[i] = '0';
        }
    }
    bs1[8] = '\0';
    cout << "Изменненная 1 строка: " << bs1 << endl;

    for (int i = 7; i >= 0; i--) {
        if (lenB > 0) {
            bs2[i] = bs2[lenB - 1];
            lenB--;
        } else {
            bs2[i] = '0';
        }
    }
    bs2[8] = '\0';
    cout << "Изменненная 2 строка: " << bs2 << endl;

    for (int i = 0; i < 8; i++) {
        if (bs1[i] == '1' && bs2[i] == '1') {
            bs1[i] = '1';
        } else {
            bs1[i] = '0';
        }
    }

    cout << "Результат AND: " << bs1 << endl;
    return 0;
}
