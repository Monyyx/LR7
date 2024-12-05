#include "func_3.h"

// TODO проверка на ввод корректных символов для строки
// HOW IT WORKS : throw std::invalid_argument("Invalid value");

void reverse (std::string &result) {
    size_t size = result.length();
    for (size_t i = 0; i < size / 2; ++i){
        std::swap(result[i], result[size - 1 - i]);
    }
}

std::string toUpperCase(std::string& str) {
    for(char &c : str){
        if('a' <= c && 'z' >= c) c = 'A' + c - 'a';
    }
}

int charToValue(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else if ('A' <= c && c <= 'Z') return c - 'A' + 10;
}

char valueToChar(int value) {
    if (0 <= value && value <= 9) return '0' + value;
    else if (10 <= value < 36) return 'A' + value - 10;
    throw std::invalid_argument("Invalid value");
}

// сложения
std::string addNumbers(int base, std::string& num1, std::string& num2) {
    int maxLength = std::max(num1.size(), num2.size());
    std::string n1 = std::string(maxLength - num1.size(), '0') + toUpperCase(num1);
    std::string n2 = std::string(maxLength - num2.size(), '0') + toUpperCase(num2);
    int carry = 0;
    std::string result;

    for (int i = maxLength - 1; i >= 0; --i) {
        int digitSum = charToValue(n1[i]) + charToValue(n2[i]) + carry;
        carry = digitSum / base;
        result += valueToChar(digitSum % base);
    }

    if (carry) result += valueToChar(carry);

    reverse(result);
    return result;
}

//вычитания
std::string subtractNumbers(int base, std::string& num1, std::string& num2) {
    int maxLength = std::max(num1.size(), num2.size());
    std::string n1 = std::string(maxLength - num1.size(), '0') + toUpperCase(num1);
    std::string n2 = std::string(maxLength - num2.size(), '0') + toUpperCase(num2);
    int borrow = 0;
    std::string result;

    for (int i = maxLength - 1; i >= 0; --i) {
        int digitDiff = charToValue(n1[i]) - charToValue(n2[i]) - borrow;
        if (digitDiff < 0) {
            digitDiff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += valueToChar(digitDiff);
    }

    // Удаляем ведущие нули
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result);
    return result;
}


void ExplainTask3() {
    std::cout << "The user inputs the base of the numeral system. Perform addition and subtraction of numbers in the given numeral system.\n"
              << "Do not convert to another numeral system. For numeral systems larger than decimal, use letters similar to the hexadecimal system.\n"
              << "Develop functions to perform the addition operation and functions to perform the subtraction operation.\n"
              << "Ensure the input of both positive and negative numbers.\n";
}

void InputValues3(){
    size_t numberSystem = 0;
    while (true) {
            std::cin >> numberSystem;
            if (std::cin.fail() || numberSystem < 2 || numberSystem > 36) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer: ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer: ";
            } else {
                break;
            }
        }


    std::string firstNumber;
    std::string secondNumber;
    std::cout << "Enter the first nember in your number system ( " << numberSystem << " ): \n";
    
}
