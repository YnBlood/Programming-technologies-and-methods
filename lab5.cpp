#include "BitString.h"

int main() {
    BitString a;
    BitString b;
    BitString c;

    string str1;
    string str2;

    int way = 0;

    cout << "Выберите способ ввода:" << endl;
    cout << "1 - с консоли" << endl;
    cout << "2 - из файла" << endl;
    cin >> way;

    if (way == 1) {
        cout << "Введите первую битовую строку: ";
        cin >> str1;

        cout << "Введите вторую битовую строку: ";
        cin >> str2;

        if (str1.length() > 8 || str2.length() > 8) {
            cout << "Ошибка, длина строки больше 8 бит. " << endl;
            return 0;
        }

        if (!a.setString(str1)) {
            cout << "Ошибка, первая строка введена неккоректно. " << endl;
            return 0;
        }

        if (!b.setString(str2)) {
            cout << "Ошибка, вторая строка введена неккоректно. " << endl;
            return 0;
        }
    } else if (way == 2) {
        if (!a.fileInput("input.txt", 1) || !b.fileInput("input.txt", 2)) {
            cout << "Ошибка, файл не открылся. " << endl;
            return 0;
        }

        cout << "Первая строка из файла: ";
        a.output();

        cout << "Вторая строка из файла: ";
        b.output();
    } else {
        cout << "Ошибка, неверный способ ввода. " << endl;
        return 0;
    }

    cout << "Изменненная 1 строка: ";
    a.output();

    cout << "Изменненная 2 строка: ";
    b.output();

    c = a.conjunction(b);

    cout << "Результат AND: ";
    c.output();

    if (a.fileOutput("output.txt", "Изменненная 1 строка: ", false) &&
        b.fileOutput("output.txt", "Изменненная 2 строка: ", true) &&
        c.fileOutput("output.txt", "Результат AND: ", true)) {
        cout << "Результат записан в файл. " << endl;
    } else {
        cout << "Ошибка, файл для записи не открылся. " << endl;
    }

    return 0;
}
