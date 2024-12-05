#include "func_1.h"
#include "func_2.h"

std::string sumOfBinary(std::string binaryFirst, std::string binarySecond) {
    if (binarySecond.length() > binaryFirst.length()) {
        std::swap(binaryFirst, binarySecond);
    }

    // Align lengths by adding leading zeros
    while (binarySecond.length() < binaryFirst.length()) {
        binarySecond.insert(binarySecond.begin(), '0');
    }

    std::string result(binaryFirst.length() + 1, '0');
    int carry = 0;
    int j = binarySecond.length() - 1;

    for (int i = binaryFirst.length() - 1; i >= 0; --i) {
        int sum = carry + (binaryFirst[i] - '0');
        if (j >= 0) {
            sum += (binarySecond[j] - '0');
            --j;
        }
        carry = sum / 2;
        result[i + 1] = (sum % 2) + '0';
    }

    result[0] = carry + '0';
    
    return result;
}

std::string checkAndAddOne(std::string binary) { 
        if (!binary.empty() && binary[0] == '1') { 
            std::string one = "1"; 
            return sumOfBinary(binary, one); 
            } 
            return binary;
        }

long long BinaryTo10(std::string &result, bool doublePlus) {
    size_t size = result.length();
    long long num = 0;
    if (result[1] == '1' && !doublePlus) {
        for(char &c : result){
            c = (c == '0') ? '1' : '0';
        }
        for (size_t i = 1; i < size; ++i) {
            num += std::pow(2, size - i - 1) * (result[i] - '0');
        }
        num = -(num);
    } else {
        for (size_t i = 1; i < size; ++i) {
            num += std::pow(2, size - i - 1) * (result[i] - '0');
        }
    }
    return num;
}


void ExplainTask2() {
    std::cout << "Perform the addition of numbers as per the given instructions. Develop functions to perform the addition operation.\n"
              << "Ensure that the program handles both positive and negative numbers. The length of the input numbers is not limited.\n"
              << "Find the sum of the binary numbers given in their natural form. Perform the addition in ones' complement form.\n"
              << "Express the answer in the natural form.\n";
}

void InputValues2(){
    long long first, second;
    std::cout << "Please enter a first integer number: ";
    inputCheck(first);
    std::cout << "Please enter a second integer number: ";
    inputCheck(second);
    bool doublePlus = (first > 0 && second > 0) ? true : false;

    bool carryOut = false;
    std::string binaryFirst = AnyNumberToReverse(first);
    std::string binarySecond = AnyNumberToReverse(second);
    std::string result = sumOfBinary(binaryFirst, binarySecond);

    checkAndAddOne(result);
    std::cout << result << '\n';
    long long normalNum = BinaryTo10(result, doublePlus);
    std::cout << "Result of summary of 2 numbers: " << normalNum;
}