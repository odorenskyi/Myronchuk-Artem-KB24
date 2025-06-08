#ifndef MODULES_MYRONCHUK_H
#define MODULES_MYRONCHUK_H

#include <string>

double s_calculation(double x, double y, double z);

bool task_10_1(const std::string& input_filename, const std::string& output_filename);
bool task_10_2(const std::string& filename);
bool task_10_3(double x, double y, double z, unsigned int b, const std::string& output_filename);
bool findWholeWord(const std::string& text, const std::string& word);
std::string toBinary(unsigned int number);
std::string getCurrentDate();

#endif
