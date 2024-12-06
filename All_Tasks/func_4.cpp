#include "func_4.h"

bool isDivisible(long long number, long long prime){// O(n)
    number = std::abs(number);
    while(number >= prime){
        number += (~prime + 1); // working like two`s codmplement
    }
    return number == 0;
}

void InputValues4(){// O(n)
    long long number, prime;
    std::cout << "Enter ypur number : ";
    inputCheck(number);
    std::cout << "Enter testing prime: ";
    inputCheck(prime);
    if(isDivisible(number, prime)) {
        std::cout << "Your number ( " << number << " ) is divisible by - " << prime << '\n';
    } else {
        std::cout << "Unluck, but your number ( " << number << " ) is not divisible by - " << prime << '\n';
    }
    std::cout << number << '\n' << ~number;
}

void ExplainTask4(){// O(1)
    std::cout << "It is necessary to develop a program that checks\n"
              << "whether the number entered by the user is divisible by a given prime.\n" 
              << "Banned operations: multiplication, division, and subtraction (including\n" 
              << "taking the remainder of the division).\n";
}