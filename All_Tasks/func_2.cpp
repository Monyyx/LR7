#include <func_1.h>
#include <func_2.h>

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
;
    std::string binaryFirst = AnyNumberToReverse(first);
    std::string binarySecond = AnyNumberToReverse(second);

    size_t size = std::max(binaryFirst.length(), binarySecond.length());

    std::string result = 
}