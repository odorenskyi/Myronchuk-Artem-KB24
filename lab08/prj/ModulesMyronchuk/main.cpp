#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// Функція обчислення S з проміжними виводами
double s_calculation(double x, double y, double z) {
    // Обчислюємо підкореневий вираз знаменника
    double cosValue = cos(z + y * z) + x * x;
    cout << "cos(z + yz) + x^2 = " << cosValue << endl;
    if (cosValue <= 0) {
        throw runtime_error("Знаменник під коренем є недопустимим (менше або дорівнює нулю)!");
    }

    double denominator = sqrt(cosValue);
    cout << "Знаменник: sqrt(cosValue) = " << denominator << endl;

    // Обчислюємо підкореневий вираз чисельника
    double absValue = fabs(y - 0.5 * z);
    cout << "abs(y - 0.5 * z) = " << absValue << endl;

    double sqrtAbsValue = sqrt(absValue);
    cout << "sqrt(absValue) = " << sqrtAbsValue << endl;

    double numerator = pow(2 * z + 1, 2) - sqrtAbsValue;
    cout << "Чисельник: (2z + 1)^2 - sqrt(absValue) = " << numerator << endl;

    // Перевірка на ділення на нуль
    if (denominator == 0) {
        throw runtime_error("Ділення на нуль: некоректні вхідні значення.");
    }

    double fraction = numerator / denominator;
    cout << "Частка: numerator / denominator = " << fraction << endl;

    double result = z + M_PI * fraction;
    cout << "Результат: S = " << result << endl;

    return result;
}
