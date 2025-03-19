#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// ������� ���������� S � ��������� ��������
double s_calculation(double x, double y, double z) {
    // ���������� ����������� ����� ����������
    double cosValue = cos(z + y * z) + x * x;
    cout << "cos(z + yz) + x^2 = " << cosValue << endl;
    if (cosValue <= 0) {
        throw runtime_error("��������� �� ������� � ������������ (����� ��� ������� ����)!");
    }

    double denominator = sqrt(cosValue);
    cout << "���������: sqrt(cosValue) = " << denominator << endl;

    // ���������� ����������� ����� ����������
    double absValue = fabs(y - 0.5 * z);
    cout << "abs(y - 0.5 * z) = " << absValue << endl;

    double sqrtAbsValue = sqrt(absValue);
    cout << "sqrt(absValue) = " << sqrtAbsValue << endl;

    double numerator = pow(2 * z + 1, 2) - sqrtAbsValue;
    cout << "���������: (2z + 1)^2 - sqrt(absValue) = " << numerator << endl;

    // �������� �� ������ �� ����
    if (denominator == 0) {
        throw runtime_error("ĳ����� �� ����: ��������� ����� ��������.");
    }

    double fraction = numerator / denominator;
    cout << "������: numerator / denominator = " << fraction << endl;

    double result = z + M_PI * fraction;
    cout << "���������: S = " << result << endl;

    return result;
}
