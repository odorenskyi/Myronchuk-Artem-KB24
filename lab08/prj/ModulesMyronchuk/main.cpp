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

bool findWholeWord(const std::string& text, const std::string& word) {
    std::string lowerText = text;
    std::string lowerWord = word;

    // ������������ � ����� ������ ��� ���������
    std::transform(lowerText.begin(), lowerText.end(), lowerText.begin(), ::tolower);
    std::transform(lowerWord.begin(), lowerWord.end(), lowerWord.begin(), ::tolower);

    size_t pos = 0;
    while ((pos = lowerText.find(lowerWord, pos)) != std::string::npos) {
        // ����������, �� � ������� �� �� ���� �����
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
    // ��������� ������ ������ �����
    if (!dateStr.empty() && dateStr.back() == '\n') {
        dateStr.pop_back();
    }
    return dateStr;
}

bool task_10_1(const std::string& input_filename, const std::string& output_filename) {
    // ³�������� ������� ���� ��� �������
    std::ifstream input_file(input_filename);
    if (!input_file.is_open()) {
        std::cerr << "�������: �� ������� ������� ���� " << input_filename << std::endl;
        return false;
    }

    // ������ ���� ����� � �����
    std::string content((std::istreambuf_iterator<char>(input_file)),
                        std::istreambuf_iterator<char>());
    input_file.close();

    // ³�������� �������� ���� ��� ������
    std::ofstream output_file(output_filename);
    if (!output_file.is_open()) {
        std::cerr << "�������: �� ������� �������� ���� " << output_filename << std::endl;
        return false;
    }

    // �������� ��������� ����������
    output_file << "=== ��������� �������ֲ� ===" << std::endl;
    output_file << "���������: ����� ��������" << std::endl;
    output_file << "��������: ����" << std::endl;
    output_file << "̳���: �������������" << std::endl;
    output_file << "�����: ������" << std::endl;
    output_file << "г� ��������: 2025" << std::endl;
    output_file << "================================" << std::endl << std::endl;

    // ϳ��������� ������� �������
    size_t char_count = content.length();
    output_file << "� ���� " << input_filename << " �������� " << char_count << " �������." << std::endl << std::endl;

    // ���������� �������� �������� ���
    std::vector<std::string> keywords = {"��������", "������", "�������", "���������"};
    std::vector<std::string> found_words;

    for (const auto& word : keywords) {
        if (findWholeWord(content, word)) {
            found_words.push_back(word);
        }
    }

    if (found_words.empty()) {
        output_file << "� ���� �� �������� ������� � �������� ���." << std::endl;
    } else {
        output_file << "� ���� �������� �����: ";
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
    // ³�������� ���� ��� �����������
    std::ofstream file(filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "�������: �� ������� ������� ���� " << filename << " ��� �����������" << std::endl;
        return false;
    }

    // �������� ������� ������� ������
    file << std::endl << "=== ������Ͳ ������� ������� ===" << std::endl;
    file << "����� � ������� 20 ����������� ������:" << std::endl;
    file << "- ��������� ������ ������" << std::endl;
    file << "- ��������� ���� ������" << std::endl;
    file << "- ��������� ó�� ������" << std::endl;
    file << "================================" << std::endl;

    // ������ ���� �������������
    file << "���� �������������: " << getCurrentDate() << std::endl;

    file.close();
    return true;
}

bool task_10_3(double x, double y, double z, unsigned int b, const std::string& output_filename) {
    // ³�������� ���� ��� �����������
    std::ofstream file(output_filename, std::ios::app);
    if (!file.is_open()) {
        std::cerr << "�������: �� ������� ������� ���� " << output_filename << " ��� ������" << std::endl;
        return false;
    }

    // ���������� ��������� ������� s_calculation
    double result = s_calculation(x, y, z);

    // �������� ���������� ���������
    file << std::endl << "=== ���������� ��������� ===" << std::endl;
    file << "������� s_calculation(" << x << ", " << y << ", " << z << ") = " << result << std::endl;

    // ������������ ����� � �������� ���
    std::string binary = toBinary(b);
    file << "����� " << b << " � ��������� ���: " << binary << std::endl;
    file << "=============================" << std::endl;

    file.close();
    return true;
}
