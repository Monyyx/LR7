#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "func_1.h"


void ExplainTask3();

void InputValues3();

void performOperation(int base, std::string num1, std::string num2, char op);

std::string addNumbers(int base, std::string num1, std::string num2);

std::string subtractNumbers(int base, std::string num1, std::string num2);

bool isValidNumber(std::string& number, int base);

char valueToChar(int value);

int charToValue(char c);

bool isDigit(char c);

bool isAlpha(char c);

std::string toUpperCase(std::string& str);