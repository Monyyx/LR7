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
    return str;
}

bool isAlpha(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
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

bool isValidNumber(std::string& number, int base) {
    for (char c : number) {
        int value;
        if (isDigit(c)) {
            value = c - '0';
        } else if (isAlpha(c)) {
            value = c - 'A' + 10;
        } else {
            return false; 
        }
        if (value >= base) {
            return false; 
        }
    }
    return true;
}

// сложения
std::string addNumbers(int base, std::string& num1, std::string& num2) {
    int maxLength = std::max(num1.size(), num2.size());
    std::string n1 = std::string(maxLength - num1.size(), '0') + toUpperCase(num1);
    std::string n2 = std::string(maxLength - num2.size(), '0') + toUpperCase(num2);
    int temp = 0;
    std::string result;

    for (int i = maxLength - 1; i >= 0; --i) {
        int digitSum = charToValue(n1[i]) + charToValue(n2[i]) + temp;
        temp = digitSum / base;
        result += valueToChar(digitSum % base);
    }

    if (temp) result += valueToChar(temp);

    reverse(result);
    return result;
}

//вычитания
std::string subtractNumbers(int base, std::string& num1, std::string& num2) {
    int maxLength = std::max(num1.size(), num2.size());
    std::string n1 = std::string(maxLength - num1.size(), '0') + toUpperCase(num1);
    std::string n2 = std::string(maxLength - num2.size(), '0') + toUpperCase(num2);
    int temp = 0;
    std::string result;

    for (int i = maxLength - 1; i >= 0; --i) {
        int digitDiff = charToValue(n1[i]) - charToValue(n2[i]) - temp;
        if (digitDiff < 0) {
            digitDiff += base;
            temp = 1;
        } else {
            temp = 0;
        }
        result += valueToChar(digitDiff);
    }

    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }

    reverse(result);
    return result;
}

void performOperation(int base, std::string& num1, std::string& num2, char op) {
    std::string result;
    if (op == '+') { 
        result = addNumbers(base, num1, num2); 
        } else if (op == '-') { 
            result = subtractNumbers(base, num1, num2); 
        } else { 
            std::cout << "Invalid operation.\n";
            return; 
            } 
            std::cout << "Result: " << result << "\n";
}

void ExplainTask3() {
    std::cout << "The user inputs the base of the numeral system. Perform addition and subtraction of numbers in the given numeral system.\n"
              << "Do not convert to another numeral system. For numeral systems larger than decimal, use letters similar to the hexadecimal system.\n"
              << "Develop functions to perform the addition operation and functions to perform the subtraction operation.\n"
              << "Ensure the input of both positive and negative numbers.\n";
}

//void InputValues3()
int main(){
    size_t numberSystem = 0;
    std::cout << "Enter your number system: ";
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

    std::string first;
    std::string second;
    while (true) {
        std::cout << "Enter a first number in your number system: ";
        std::cin >> first;
        toUpperCase(first);
        if (!isValidNumber(first,numberSystem)) {
            std::cout << "Invalid number for the given number system. Please enter a valid number.\n";
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "Enter a second number in your number system: ";
        std::cin >> second;
        toUpperCase(second);
        if (!isValidNumber(first,numberSystem)) {
            std::cout << "Invalid number for the given number system. Please enter a valid number.\n";
        } else {
            break;
        }
    }
    char operat;
    while (true) {
        std::cout << "Enter the operation (+ or -): ";
        std::cin >> operat; 
        if (operat == '+' || operat == '-') { 
            break; 
        } else { 
            std::cout << "Invalid input. Please enter either + or -.\n"; 
            } 
    }
    
    performOperation(numberSystem, first, second, operat);
    return 0;
}
