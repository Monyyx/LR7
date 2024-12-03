#include <func_1.h>
#include <func_2.h>


std::string addBinary(std::string binaryFirst, std::string binarySecond) {
    if (binarySecond.length() > binaryFirst.length()) {
        std::swap(binaryFirst, binarySecond);
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

std::string sumOfBinary(long long first, long long second){

    std::string binaryFirst = AnyNumberToReverse(first);
    std::string binarySecond = AnyNumberToReverse(second);

    if (binarySecond.length() >  binaryFirst.length()) {
        std::swap(binaryFirst, binarySecond);
    }
    std::string result = addBinary(binaryFirst, binarySecond);
    
    return result;
}
// сделать блин функцию выше чтобы она блять числа принимала двочиные и допиоить потом сделаитть перевод в десятичную 
std::string checkAndAddOne(std::string binary) { 
        if (!binary.empty() && binary[0] == '1') { 
            std::string one = "1"; 
            return sumOfBinary(binary, one); 
            } 
            return binary;
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

    std::string result = sumOfBinary(first, second);
    std::string checkAndAddOne(const std::string &binary) { 
        if (!binary.empty() && binary[0] == '1') { 
            std::string one = "1"; 
            return addBinaryStrings(binary, one); 
            } 
            return binary;
        }
    

}