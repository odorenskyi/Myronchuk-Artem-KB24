#include "ModulesMyronchuk.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <functional>

// Структура для тест-кейса
struct TestCase {
    std::string name;
    std::string description;
    std::function<bool()> test_function;
};

// Функція для створення тестового файлу
bool createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << content;
    file.close();
    return true;
}

// Функція для читання вмісту файлу
std::string readFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    return content;
}

// Функція для перевірки наявності підрядка в тексті
bool containsSubstring(const std::string& text, const std::string& substring) {
    return text.find(substring) != std::string::npos;
}

// Тест-кейси для задачі 10.1
bool test_10_1_case_1() {
    std::cout << "  Тестуємо задачу 10.1 - Кейс 1..." << std::endl;

    // Створюємо тестовий файл
    std::string input_content = "Це програма для студента. Модуль працює добре.";
    if (!createTestFile("test_input1.txt", input_content)) {
        std::cout << "    FAILED: Не вдалося створити тестовий файл" << std::endl;
        return false;
    }

    // Викликаємо функцію
    bool result = task_10_1("test_input1.txt", "test_output1.txt");
    if (!result) {
        std::cout << "    FAILED: Функція повернула false" << std::endl;
        return false;
    }

    // Перевіряємо результат
    std::string output = readFile("test_output1.txt");
    if (output.empty()) {
        std::cout << "    FAILED: Вихідний файл порожній або не існує" << std::endl;
        return false;
    }

    // Перевіряємо наявність очікуваних рядків
    bool has_author = containsSubstring(output, "Мирончук");
    bool has_count = containsSubstring(output, "84 символів") || containsSubstring(output, "51 символ");
    bool has_words = containsSubstring(output, "програма") && containsSubstring(output, "студента") && containsSubstring(output, "модуль");

    if (has_author || has_count || has_words) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: Не всі очікувані елементи знайдено в вихідному файлі" << std::endl;
        return false;
    }
}

bool test_10_1_case_2() {
    std::cout << "  Тестуємо задачу 10.1 - Кейс 2..." << std::endl;

    std::string input_content = "Програміст розробляє модульну систему для студентки.";
    if (!createTestFile("test_input2.txt", input_content)) {
        std::cout << "    FAILED: Не вдалося створити тестовий файл" << std::endl;
        return false;
    }

    bool result = task_10_1("test_input2.txt", "test_output2.txt");
    if (!result) {
        std::cout << "    FAILED: Функція повернула false" << std::endl;
        return false;
    }

    std::string output = readFile("test_output2.txt");
    bool has_programmer = containsSubstring(output, "програміст");
    bool has_student = containsSubstring(output, "студент");

    if (has_programmer || has_student) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: Не знайдено очікувані слова" << std::endl;
        return false;
    }
}

// Тест-кейси для задачі 10.2
bool test_10_2_case_1() {
    std::cout << "  Тестуємо задачу 10.2 - Кейс 1..." << std::endl;

    std::string initial_content = "Початковий текст файлу.";
    if (!createTestFile("test_append1.txt", initial_content)) {
        std::cout << "    FAILED: Не вдалося створити тестовий файл" << std::endl;
        return false;
    }

    bool result = task_10_2("test_append1.txt");
    if (!result) {
        std::cout << "    FAILED: Функція повернула false" << std::endl;
        return false;
    }

    std::string output = readFile("test_append1.txt");
    bool has_initial = containsSubstring(output, "Початковий текст");
    bool has_symbols = containsSubstring(output, "Державний Прапор") &&
                      containsSubstring(output, "Державний Герб") &&
                      containsSubstring(output, "Державний Гімн");
    bool has_date = containsSubstring(output, "Дата дозаписування");

    if (has_initial && has_symbols && has_date) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: Не всі очікувані елементи знайдено" << std::endl;
        return false;
    }
}

// Тест-кейси для задачі 10.3
bool test_10_3_case_1() {
    std::cout << "  Тестуємо задачу 10.3 - Кейс 1..." << std::endl;

    createTestFile("test_calc1.txt", ""); // Створюємо порожній файл

    bool result = task_10_3(2.5, 3.0, 1.5, 10, "test_calc1.txt");
    if (!result) {
        std::cout << "    FAILED: Функція повернула false" << std::endl;
        return false;
    }

    std::string output = readFile("test_calc1.txt");
    bool has_calculation = containsSubstring(output, "s_calculation");
    bool has_binary = containsSubstring(output, "1010"); // 10 в двійковому коді

    if (has_calculation && has_binary) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: Не знайдено очікувані результати" << std::endl;
        return false;
    }
}

// Функція для запуску всіх тестів
void runAllTests() {
    std::cout << "=== ЗАПУСК АВТОМАТИЗОВАНОГО ТЕСТУВАННЯ ===" << std::endl;
    std::cout << "Дата початку тестування: " << getCurrentDate() << std::endl << std::endl;

    std::vector<std::pair<std::string, std::function<bool()>>> tests = {
        {"Задача 10.1 - Кейс 1", test_10_1_case_1},
        {"Задача 10.1 - Кейс 2", test_10_1_case_2},
        {"Задача 10.2 - Кейс 1", test_10_2_case_1},
        {"Задача 10.3 - Кейс 1", test_10_3_case_1}
    };

    int passed = 0;
    int total = tests.size();

    for (const auto& test : tests) {
        std::cout << "Тестування: " << test.first << std::endl;
        if (test.second()) {
            passed++;
        }
        std::cout << std::endl;
    }

    std::cout << "=== РЕЗУЛЬТАТИ ТЕСТУВАННЯ ===" << std::endl;
    std::cout << "Пройдено тестів: " << passed << "/" << total << std::endl;
    std::cout << "Відсоток успішності: " << (passed * 100.0 / total) << "%" << std::endl;

    if (passed == total) {
        std::cout << "? Всі тести пройдено успішно!" << std::endl;
    } else {
        std::cout << "? Деякі тести не пройшли перевірку." << std::endl;
    }
}

int main() {
    system("chcp 1251 && cls");
    std::cout << "ТЕСТОВИЙ ДРАЙВЕР для лабораторної роботи №10" << std::endl;
    std::cout << "===========================================" << std::endl;

    runAllTests();

    std::cout << std::endl << "Натисніть Enter для завершення...";
    std::cin.get();

    return 0;
}
