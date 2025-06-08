#include "ModulesMyronchuk.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <functional>

// ��������� ��� ����-�����
struct TestCase {
    std::string name;
    std::string description;
    std::function<bool()> test_function;
};

// ������� ��� ��������� ��������� �����
bool createTestFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << content;
    file.close();
    return true;
}

// ������� ��� ������� ����� �����
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

// ������� ��� �������� �������� ������� � �����
bool containsSubstring(const std::string& text, const std::string& substring) {
    return text.find(substring) != std::string::npos;
}

// ����-����� ��� ������ 10.1
bool test_10_1_case_1() {
    std::cout << "  ������� ������ 10.1 - ���� 1..." << std::endl;

    // ��������� �������� ����
    std::string input_content = "�� �������� ��� ��������. ������ ������ �����.";
    if (!createTestFile("test_input1.txt", input_content)) {
        std::cout << "    FAILED: �� ������� �������� �������� ����" << std::endl;
        return false;
    }

    // ��������� �������
    bool result = task_10_1("test_input1.txt", "test_output1.txt");
    if (!result) {
        std::cout << "    FAILED: ������� ��������� false" << std::endl;
        return false;
    }

    // ���������� ���������
    std::string output = readFile("test_output1.txt");
    if (output.empty()) {
        std::cout << "    FAILED: �������� ���� ������� ��� �� ����" << std::endl;
        return false;
    }

    // ���������� �������� ���������� �����
    bool has_author = containsSubstring(output, "��������");
    bool has_count = containsSubstring(output, "84 �������") || containsSubstring(output, "51 ������");
    bool has_words = containsSubstring(output, "��������") && containsSubstring(output, "��������") && containsSubstring(output, "������");

    if (has_author || has_count || has_words) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: �� �� �������� �������� �������� � ��������� ����" << std::endl;
        return false;
    }
}

bool test_10_1_case_2() {
    std::cout << "  ������� ������ 10.1 - ���� 2..." << std::endl;

    std::string input_content = "��������� ��������� �������� ������� ��� ���������.";
    if (!createTestFile("test_input2.txt", input_content)) {
        std::cout << "    FAILED: �� ������� �������� �������� ����" << std::endl;
        return false;
    }

    bool result = task_10_1("test_input2.txt", "test_output2.txt");
    if (!result) {
        std::cout << "    FAILED: ������� ��������� false" << std::endl;
        return false;
    }

    std::string output = readFile("test_output2.txt");
    bool has_programmer = containsSubstring(output, "���������");
    bool has_student = containsSubstring(output, "�������");

    if (has_programmer || has_student) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: �� �������� �������� �����" << std::endl;
        return false;
    }
}

// ����-����� ��� ������ 10.2
bool test_10_2_case_1() {
    std::cout << "  ������� ������ 10.2 - ���� 1..." << std::endl;

    std::string initial_content = "���������� ����� �����.";
    if (!createTestFile("test_append1.txt", initial_content)) {
        std::cout << "    FAILED: �� ������� �������� �������� ����" << std::endl;
        return false;
    }

    bool result = task_10_2("test_append1.txt");
    if (!result) {
        std::cout << "    FAILED: ������� ��������� false" << std::endl;
        return false;
    }

    std::string output = readFile("test_append1.txt");
    bool has_initial = containsSubstring(output, "���������� �����");
    bool has_symbols = containsSubstring(output, "��������� ������") &&
                      containsSubstring(output, "��������� ����") &&
                      containsSubstring(output, "��������� ó��");
    bool has_date = containsSubstring(output, "���� �������������");

    if (has_initial && has_symbols && has_date) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: �� �� �������� �������� ��������" << std::endl;
        return false;
    }
}

// ����-����� ��� ������ 10.3
bool test_10_3_case_1() {
    std::cout << "  ������� ������ 10.3 - ���� 1..." << std::endl;

    createTestFile("test_calc1.txt", ""); // ��������� ������� ����

    bool result = task_10_3(2.5, 3.0, 1.5, 10, "test_calc1.txt");
    if (!result) {
        std::cout << "    FAILED: ������� ��������� false" << std::endl;
        return false;
    }

    std::string output = readFile("test_calc1.txt");
    bool has_calculation = containsSubstring(output, "s_calculation");
    bool has_binary = containsSubstring(output, "1010"); // 10 � ��������� ���

    if (has_calculation && has_binary) {
        std::cout << "    PASSED" << std::endl;
        return true;
    } else {
        std::cout << "    FAILED: �� �������� �������� ����������" << std::endl;
        return false;
    }
}

// ������� ��� ������� ��� �����
void runAllTests() {
    std::cout << "=== ������ ���������������� ���������� ===" << std::endl;
    std::cout << "���� ������� ����������: " << getCurrentDate() << std::endl << std::endl;

    std::vector<std::pair<std::string, std::function<bool()>>> tests = {
        {"������ 10.1 - ���� 1", test_10_1_case_1},
        {"������ 10.1 - ���� 2", test_10_1_case_2},
        {"������ 10.2 - ���� 1", test_10_2_case_1},
        {"������ 10.3 - ���� 1", test_10_3_case_1}
    };

    int passed = 0;
    int total = tests.size();

    for (const auto& test : tests) {
        std::cout << "����������: " << test.first << std::endl;
        if (test.second()) {
            passed++;
        }
        std::cout << std::endl;
    }

    std::cout << "=== ���������� ���������� ===" << std::endl;
    std::cout << "�������� �����: " << passed << "/" << total << std::endl;
    std::cout << "³������ ��������: " << (passed * 100.0 / total) << "%" << std::endl;

    if (passed == total) {
        std::cout << "? �� ����� �������� ������!" << std::endl;
    } else {
        std::cout << "? ���� ����� �� ������� ��������." << std::endl;
    }
}

int main() {
    system("chcp 1251 && cls");
    std::cout << "�������� ������� ��� ����������� ������ �10" << std::endl;
    std::cout << "===========================================" << std::endl;

    runAllTests();

    std::cout << std::endl << "�������� Enter ��� ����������...";
    std::cin.get();

    return 0;
}
