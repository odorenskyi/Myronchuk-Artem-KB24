#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <ctime>
#include <vector>

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

bool findWholeWord(const std::string& text, const std::string& word) {
    std::string lowerText = text;
    std::string lowerWord = word;

    // Перетворюємо в нижній регістр для порівняння
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    size_t pos = 0;
    while ((pos = lowerText.find(lowerWord, pos)) != std::string::npos) {
        // Перевіряємо, чи є символи до та після слова
        bool validStart = (pos == 0) || !std::isalnum(lowerText[pos - 1]);
        bool validEnd = (pos + lowerWord.length() >= lowerText.length()) ||
                       !std::isalnum(lowerText[pos + lowerWord.length()]);

        if (validStart && validEnd) {
            return true;
        }
        pos++;
    }
    return false;
}

std::string toBinary(unsigned int number) {
    if (number == 0) return "0";

    std::string binary = "";
    while (number > 0) {
        binary = (number % 2 == 0 ? "0" : "1") + binary;
        number /= 2;
    }
    return binary;
}

std::string getCurrentDate() {
    time_t now = time(0);
    char* timeStr = ctime(&now);
    std::string dateStr(timeStr);
    // Видаляємо символ нового рядка
    if (!dateStr.empty() && dateStr.back() == '\n') {
        dateStr.pop_back();
    }
    return dateStr;
}

bool task_10_1(const std::string& input_filename, const std::string& output_filename) {
    // Відкриваємо вхідний файл для читання
    std::ifstream input_file(input_filename);
    if (!input_file.is_open()) {
        std::cerr << "Помилка: не вдалося відкрити файл " << input_filename << std::endl;
        return false;
    }

    // Читаємо весь текст з файлу
    std::string content((std::istreambuf_iterator<char>(input_file)),
                        std::istreambuf_iterator<char>());
    input_file.close();

    // Відкриваємо вихідний файл для запису
    std::ofstream output_file(output_filename);
    if (!output_file.is_open()) {
        std::cerr << "Помилка: не вдалося створити файл " << output_filename << std::endl;
        return false;
    }

    // Записуємо авторську інформацію
    output_file << "=== АВТОРСЬКА ІНФОРМАЦІЯ ===" << std::endl;
    output_file << "Розробник: Артем Мирончук" << std::endl;
    output_file << "Установа: ЦНТУ" << std::endl;
    output_file << "Місто: Кропивницький" << std::endl;
    output_file << "Країна: Україна" << std::endl;
    output_file << "Рік розробки: 2025" << std::endl;
    output_file << "================================" << std::endl << std::endl;

    // Підраховуємо кількість символів
    size_t char_count = content.length();
    output_file << "У файлі " << input_filename << " міститься " << char_count << " символів." << std::endl << std::endl;

    // Перевіряємо наявність ключових слів
    std::vector<std::string> keywords = {"програма", "модуль", "студент", "програміст"};
    std::vector<std::string> found_words;

    for (const auto& word : keywords) {
        if (findWholeWord(content, word)) {
            found_words.push_back(word);
        }
    }

    if (found_words.empty()) {
        output_file << "У файлі не знайдено жодного з ключових слів." << std::endl;
    } else {
        output_file << "У файлі знайдено слова: ";
        for (size_t i = 0; i < found_words.size(); ++i) {
            output_file << found_words[i];
            if (i < found_words.size() - 1) {
                output_file << ", ";
            }
        }
        output_file << std::endl;
    }

    output_file.close();
    return true;
}

bool task_10_2(const std::string& filename) {
    // Відкриваємо файл для дописування
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Помилка: не вдалося відкрити файл " << filename << " для дописування" << std::endl;
        return false;
    }

    // Дописуємо державні символи України
    file << std::endl << "=== ДЕРЖАВНІ СИМВОЛИ УКРАЇНИ ===" << std::endl;
    file << "Згідно зі статтею 20 Конституції України:" << std::endl;
    file << "- Державний Прапор України" << std::endl;
    file << "- Державний Герб України" << std::endl;
    file << "- Державний Гімн України" << std::endl;
    file << "================================" << std::endl;

    // Додаємо дату дозаписування
    file << "Дата дозаписування: " << getCurrentDate() << std::endl;

    file.close();
    return true;
}

bool task_10_3(double x, double y, double z, unsigned int b, const std::string& output_filename) {
    // Відкриваємо файл для дописування
    std::ofstream file(output_filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "Помилка: не вдалося відкрити файл " << output_filename << " для запису" << std::endl;
        return false;
    }

    // Обчислюємо результат функції s_calculation
    double result = s_calculation(x, y, z);

    // Записуємо результати обчислень
    file << std::endl << "=== РЕЗУЛЬТАТИ ОБЧИСЛЕНЬ ===" << std::endl;
    file << "Функція s_calculation(" << x << ", " << y << ", " << z << ") = " << result << std::endl;

    // Перетворюємо число в двійковий код
    std::string binary = toBinary(b);
    file << "Число " << b << " у двійковому коді: " << binary << std::endl;
    file << "=============================" << std::endl;

    file.close();
    return true;
}
