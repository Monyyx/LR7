#include "func_3.h"

std::string toUpperCase(std::string& str) {
    for(char &c : str){
        if('a' <= c && 'z' >= c) c = 'A' + c - 'a'; // Ручной цикл для преобразования
    }
    return str;
}

bool isAlpha(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && 'z' >= c);
}

bool isDigit(char c) {
    return '0' <= c && c <= '9';
}

int charToValue(char c) {
    if ('0' <= c && c <= '9') return c - '0';
    else if ('A' <= c && 'Z' >= c) return c - 'A' + 10;
    return -1; 
}

char valueToChar(int value) {
    if (0 <= value && value <= 9) return '0' + value;
    else if (10 <= value < 36) return 'A' + value - 10;
    return '?'; 
}

bool isValidNumber(std::string& number, int base) {
    size_t start = (number[0] == '-' || number[0] == '+') ? 1 : 0;
    for (size_t i = start; i < number.length(); ++i) {
        char c = number[i];
        if (!isAlpha(c) && !isDigit(c)) return false;
        int value = isDigit(c) ? c - '0' : c - 'A' + 10;
        if (value >= base) return false;
    }
    return true;
}

std::string addNumbers(int base, std::string num1, std::string num2);

std::string subtractNumbers(int base, std::string num1, std::string num2) {
    bool neg1 = (num1[0] == '-'), neg2 = (num2[0] == '-');
    if (neg1) num1 = num1.substr(1);
    if (neg2) num2 = num2.substr(1);

    if (neg1 != neg2) return addNumbers(base, neg1 ? '-' + num1 : num1, neg1 ? num2 : '-' + num2);
    
    bool resultNeg = false;
    if (num1 < num2) {
        std::swap(num1, num2); 
        resultNeg = true;
    }
    
    int maxLength = std::max(num1.size(), num2.size()); 
    num1 = std::string(maxLength - num1.size(), '0') + toUpperCase(num1);
    num2 = std::string(maxLength - num2.size(), '0') + toUpperCase(num2);

    int borrow = 0;
    std::string result;
    for (int i = maxLength - 1; i >= 0; --i) {
        int digitDiff = charToValue(num1[i]) - charToValue(num2[i]) - borrow;
        if (digitDiff == -1) return "Invalid number";
        if (digitDiff < 0) {
            digitDiff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += valueToChar(digitDiff);
    }
    while (result.size() > 1 && result.back() == '0') {
        result.pop_back();
    }
    reverse(result);
    if (resultNeg) result = '-' + result;
    return result;
}

std::string addNumbers(int base, std::string num1, std::string num2) {
    bool neg1 = (num1[0] == '-'), neg2 = (num2[0] == '-');
    if (neg1) num1 = num1.substr(1);
    if (neg2) num2 = num2.substr(1);

    if (neg1 != neg2) return subtractNumbers(base, neg1 ? num2 : num1, neg1 ? num1 : num2);
    
    int maxLength = std::max(num1.size(), num2.size()); 
    num1 = std::string(maxLength - num1.size(), '0') + toUpperCase(num1);
    num2 = std::string(maxLength - num2.size(), '0') + toUpperCase(num2);

    int carry = 0;
    std::string result;
    for (int i = maxLength - 1; i >= 0; --i) {
        int digitSum = charToValue(num1[i]) + charToValue(num2[i]) + carry;
        if (digitSum == -1) return "Invalid number"; 
        carry = digitSum / base;
        result += valueToChar(digitSum % base);
    }
    if (carry) result += valueToChar(carry);
    reverse(result);
    if (neg1 && neg2) result = '-' + result;
    return result;
}

void performOperation(int base, std::string num1, std::string num2, char op) {
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

void InputValues3(){
    int numberSystem = 0;
    std::cout << "Enter your number system: ";
    while (true) {
        std::cin >> numberSystem;
        if (std::cin.fail() || numberSystem < 2 || numberSystem > 36) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer: \n";
        } else if (std::cin.peek() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid integer: \n";
        } else {
            break;
        }
    }
    std::cin.ignore();
    std::string first;
    std::string second;
    while (true) {
        std::cout << "Enter a first number in your number system: \n";
        std::getline(std::cin, first);
        toUpperCase(first);
        if (!isValidNumber(first, numberSystem)) {
            std::cout << "Invalid number for the given number system. Please enter a valid number.\n";
        } else {
            break;
        }
    }
    while (true) {
        std::cout << "Enter a second number in your number system: \n";
        std::getline(std::cin ,second);
        toUpperCase(second);
        if (!isValidNumber(second, numberSystem)) {
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
}
