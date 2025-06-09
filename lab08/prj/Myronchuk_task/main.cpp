#include <iostream>
#include <locale>
#include <iomanip>
#include "ModulesMyronchuk.h"
using namespace std;

// ������� �� ��'� ����������
void printAuthor() {
    cout << "�����: �������� ��'� �" << endl;
}

// ������� ����� a + 1 >= b
bool logicalExpression(char a, char b) {
    return (a + 1) >= b;
}

// ������� ��� ���������� �����
double s_calculation(double x, double y, double z) {
    return x * y * z;
}

// ������� ��� �������� �����
void inputData(double &x, double &y, double &z, char &a, char &b) {
    cout << "������ ��� ����� (x, y, z): ";
    cin >> x >> y >> z;
    cout << "������ ��� ������� (a � b): ";
    cin >> a >> b;
}

// ������� 8.2.3: ���� �������� ������� �� ���������� S
void printValuesAndResult(double x, double y, double z) {
    cout << fixed << setprecision(2);
    cout << "����� (��������� �������): x = " << x << ", y = " << y << ", z = " << z << endl;
    cout << "����� (�������������� �������): x = " << hexfloat << x << ", y = " << y << ", z = " << z << defaultfloat << endl;

    double S = s_calculation(x, y, z);
    cout << "�����: S = " << S << endl;
}

// ������� ��� ��������� �����
void printData(double x, double y, double z, char a, char b) {
    cout << "������ �����: " << x << ", " << y << ", " << z << endl;
    cout << "������ �������: " << a << ", " << b << endl;

    // ������� �����
    cout << "������� ����� (a + 1 >= b): " << boolalpha << logicalExpression(a, b) << endl;

    // ��������� �� �������������� ������� ��������
    cout << "����� � ��������� ������: " << x << ", " << y << ", " << z << endl;
    cout << "����� � �������������� ������: " << hexfloat << x << ", " << y << ", " << z << defaultfloat << endl;

    // ���� ������� �� ����������� S
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
