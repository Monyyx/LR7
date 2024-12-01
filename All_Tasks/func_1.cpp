#include <iostream>
#include <string>
#include <algorithm>

// Функция для перевода числа в двоичное представление
std::string toBinary(long long num) {
    if (num == 0) return "0";
    std::string result;
    while (num > 0) {
        result += (num % 2 == 0 ? "0" : "1");
        num /= 2;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// Функция для перевода положительных чисел в обратный код
std::string positiveToBinary(long long num) {
    return toBinary(num);
}

// Функция для перевода отрицательных чисел в обратный код
std::string negativeToBinary(long long num) {
    std::string binary = toBinary(-num);
    // Инверсия всех битов
    for (char &c : binary) {
        c = (c == '0') ? '1' : '0';
    }
    return "1" + binary;
}

int main() {
    long long number;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    std::string binaryRepresentation;
    if (number >= 0) {
        binaryRepresentation = "0" + positiveToBinary(number);
    } else {
        binaryRepresentation = negativeToBinary(number);
    }
    
    std::cout << "Двоичное представление с знаковым битом: " << binaryRepresentation << std::endl;

    return 0;
}
