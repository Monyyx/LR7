#include "func_1.h"

void reverse (std::string result) {
    size_t size = result.length();
    for (size_t i = 0; i < result.length() / 2; ++i){
        std::swap(result[i], result[size - 1 - i]);
    }
}

std::string toBinary(long long num) {
    if (num == 0) return "0";
    std::string result;
    while (num > 0) {
        result += (num % 2 == 0 ? "0" : "1");
        num /= 2;
    }
    reverse(result);
    return result;
}

std::string AnyNumberToReverse(long long num) {
    if (num >= 0)  return "0" + toBinary(num);
    else {
        std::string binary = toBinary(-num);
        for(char &c : binary){
            c = (c == '0') ? '1' : '0';
        }
        return "1" + binary;
    }
}



void InputValues1() {
    long long number;
    std::cout << "Please enter a integer number: ";
    std::cin >> number; // TODO
    
    std::string binaryRepresentation;
    binaryRepresentation = AnyNumberToReverse(number);
    
    std::cout << "Binary representation of your number is: " << binaryRepresentation << std::endl;
}

void AuthorInfo() {
    std::cout << "Completed by: Matvei Khadorik\n";
}

void ExplainTask1() {
    std::cout << "/n"; // TODO
}

void DisplayMenuTask() {
    std::cout << "--- Context menu ---\n"
              << "1. Task description\n"
              << "2. Author information\n"
              << "3. Enter Control Values\n"
              << "0. Exit\n"
              << "Choose an option: ";
}
