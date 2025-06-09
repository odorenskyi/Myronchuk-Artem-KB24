#include <iostream>
#include <locale>
#include <iomanip>
#include "ModulesMyronchuk.h"
using namespace std;

// Прізвище та ім'я розробника
void printAuthor() {
    cout << "Автор: Мирончук Ім'я ©" << endl;
}

// Логічний вираз a + 1 >= b
bool logicalExpression(char a, char b) {
    return (a + 1) >= b;
}

// Функція для обчислення площі
double s_calculation(double x, double y, double z) {
    return x * y * z;
}

// Функція для введення даних
void inputData(double &x, double &y, double &z, char &a, char &b) {
    cout << "Введіть три числа (x, y, z): ";
    cin >> x >> y >> z;
    cout << "Введіть два символи (a і b): ";
    cin >> a >> b;
}

// Функція 8.2.3: Вивід числових значень та обчислення S
void printValuesAndResult(double x, double y, double z) {
    cout << fixed << setprecision(2);
    cout << "Числа (десяткова система): x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << "Числа (шістнадцяткова система): x = " << hexfloat << x << ", y = " << y << ", z = " << z << defaultfloat << endl;

    double S = s_calculation(x, y, z);
    cout << "Площа: S = " << S << endl;
}

// Функція для виведення даних
void printData(double x, double y, double z, char a, char b) {
    cout << "Введені числа: " << x << ", " << y << ", " << z << endl;
    cout << "Введені символи: " << a << ", " << b << endl;

    // Логічний вираз
    cout << "Логічний вираз (a + 1 >= b): " << boolalpha << logicalExpression(a, b) << endl;

    // Десяткова та шістнадцяткова системи числення
    cout << "Числа у десятковій системі: " << x << ", " << y << ", " << z << endl;
    cout << "Числа у шістнадцятковій системі: " << hexfloat << x << ", " << y << ", " << z << defaultfloat << endl;

    // Вивід значень та обчисленого S
    printValuesAndResult(x, y, z);
}

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    double x, y, z;
    char a, b;
    printAuthor();
    inputData(x, y, z, a, b);
    printData(x, y, z, a, b);
    return 0;
}
