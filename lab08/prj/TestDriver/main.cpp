#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <clocale>  // Підключаємо бібліотеку для setlocale
#include "ModulesMyronchuk.h"

// Функція для виконання тесту
void run_test(double x, double y, double z, double expected, double tolerance = 1e-6) {
    std::cout << "Тест: x = " << x << ", y = " << y << ", z = " << z << std::endl;

    try {
        double result = s_calculation(x, y, z);
        std::cout << "Отриманий результат: " << std::fixed << std::setprecision(6) << result << std::endl;

        if (fabs(result - expected) < tolerance) {
            std::cout << "Статус: PASSED ✅\n" << std::endl;
        } else {
            std::cout << "Статус: FAILED ❌ (Очікувано: " << expected << ")\n" << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "Помилка виконання: " << e.what() << std::endl;
        std::cout << "Статус: FAILED ❌ (Очікувався коректний результат)\n" << std::endl;
    }
}

int main() {
    // Встановлюємо українську локаль
    setlocale(LC_ALL, "Ukrainian");

    std::cout << "=== Запуск тестового драйвера ===\n" << std::endl;

    // Набір тест-кейсів (x, y, z, очікуваний результат)
    run_test(1.0, 2.0, 3.0, 511.927768);
    run_test(0.0, 1.0, 2.0, NAN);
    run_test(1.5, -2.0, 0.5, 4.94105);
    run_test(-1.0, 0.0, 1.0, 21.99196);
    run_test(2.0, 3.0, 4.0, 148.0907);
    run_test(3.0, 4.0, 5.0, 124.044159);
    run_test(-2.0, -1.0, 0.0, 0.0);
    run_test(0.5, 0.25, 0.75, 20.939914);
    run_test(1.0, -1.0, 1.0, 18.272274);
    run_test(2.0, -3.0, -1.0, -1.964394);


    std::cout << "=== Тестування завершено ===" << std::endl;
    return 0;
}
