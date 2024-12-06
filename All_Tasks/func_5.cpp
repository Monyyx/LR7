#include "func_5.h"

void reverse (std::string &result) {
    size_t size = result.length();
    for (size_t i = 0; i < size / 2; ++i){
        std::swap(result[i], result[size - 1 - i]);
    }
}

std::string toTernary(int num) {
        std::string ternary;
        while (num > 0) {
            ternary.push_back('0' + (num % 3));
            num /= 3;
        }
        while(ternary.length() < 5){
            ternary.push_back('0');
        }
        reverse(ternary);
        return ternary;
    }

/*bool findingBarrel(std::string &slaves, int *barrels,std::string toxic, int numBarrels = 240, int numSlaves = 5){
    for (int digit = 0; digit < 2; ++digit) {
        std::cout << "After " << digit + 1 << " days:\n";

        for(int j = 0; j < numSlaves; ++j){
        for (int i = 0; i < numBarrels; ++i) {
            std::string drinkBarrel = toTernary(barrels[i]);
            if (drinkBarrel[j] == digit) {
                std::cout << "Slave " << j + 1 << " drinks from a barrel: " << barrels[i] << '\n';
            }
        }
            std::cout << "Slave " << j + 1 << " live? (1-yes, 0-nope): ";
            int alive;
            while (true) {
            std::cin >> alive;
            if (std::cin.fail() || (alive != 1 && alive != 0)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer: ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid integer: ";
            } else {
                break;
            }

            if (alive == 0) {
                slaves[j] = digit;
            }
        }
        }
    bool allDead = true;

    for (char slave : slaves) {
        if (slave == -1) {
            allDead = false;
            break;
            }
        }
    if (allDead) {
        break;
    }
}

    int number  = 0;
    for(size_t i = 0; i < numSlaves; ++i){
        if(slaves[i] == -1) slaves[i] == 2;
        number += (slaves[i] - '0') * std::pow(10, i);
    }

    return slaves == (toxic);
}*/
bool findingBarrel(std::string &slaves, int *barrels, std::string toxic, int numBarrels = 240, int numSlaves = 5) {
    for (int digit = 0; digit < 2; ++digit) {
        std::cout << "After " << digit + 1 << " days:\n";

        for (int j = 0; j < numSlaves; ++j) {
            if(slaves[j] != digit && slaves[j] == -1) {
                std::cout << "Slave " << j + 1 << " drinks from barrels: \n";
                for (int i = 0; i < numBarrels; ++i) {
                    std::string drinkBarrel = toTernary(barrels[i]);
                    if (drinkBarrel[j] == digit + '0') {
                        std::cout << barrels[i] << '\n';
                    }
                }
                std::cout << '\n';
                std::cout << "Slave " << j + 1 << " live? (1-yes, 0-nope): ";
                int alive;
                std::cin >> alive;

                while (std::cin.fail() || (alive != 1 && alive != 0)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Invalid input. Please enter a valid integer (1-yes, 0-nope): ";
                    std::cin >> alive;
                }
                if (alive == 0) {
                    slaves[j] = digit + '0';
                }
            }
        }

        bool allDead = true;
        for (char slave : slaves) {
            if (slave == -1) {
                allDead = false;
                break;
            }
        }
        if (allDead) {
            break;
        }
    }

    int number = 0;
    for (size_t i = 0; i < numSlaves; ++i) {
        if (slaves[i] == -1) slaves[i] = '2';
        number += (slaves[i] - '0') * (pow(10, i));
    }

    //return slaves == toxic;
}



void ExplainTask5() {
    std::cout << "Patrician decided to hold a feast and prepared 240 barrels of wine.\n"
              << "However, a mischief-maker named User managed to poison one of the barrels.\n"
              << "The mischief-maker was immediately caught, and his fate is unknown, but\n"
              << "rumors say that he now tests console input in hell as punishment.\n"
              << "However, that’s not our concern right now. The poison takes effect within\n"
              << "24 hours. The feast is in two days. The patrician has five slaves who he is\n"
              << "willing to sacrifice to find out which barrel contains the poison. You are a\n"
              << "close friend of the Patrician and you definitely do not want to be one of those\n"
              << "slaves testing the wine for poison.\n";
}

//void InputValues5()
int main() {
    int numBarrels = 240;
    int numSlaves = 5;
    int barrels[numBarrels];
    int toxic = 0;
    std::cout  << "Enter the toxic barrel : ";
    while (true) {
            std::cin >> toxic;
            if (std::cin.fail() || toxic <= 0 || toxic > 240) {
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
    std::string toxicIN3{5,0};

    for (int i = 0; i < numBarrels; ++i) {
        barrels[i] = i + 1;
    }
    std::string slaves(numSlaves, -1);

    if(findingBarrel(slaves, barrels, toxicIN3)){
    std::cout << "The number of the poisoned barrel: " << toxic;
    } else std::cout << ".";
    //if (lazyFindingBarrel(slaves, toxicIN3)) {
     //   std::cout << "Result: barrel - " << toxic;
    //} else  std::cout << "Unluck/";
}
