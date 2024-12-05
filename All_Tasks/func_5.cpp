#include "func_5.h"

std::string toTernary(int num) {
        std::string ternary;
        while (num > 0) {
            ternary.push_back(num % 3);
            num /= 3;
        }
        return ternary;
    }

bool findingBarrel(std::string &slaves, int *barrels,std::string toxic, int numBarrels = 240, int numSlaves = 5){
    for (int digit = 0; digit < 2; ++digit) {
        /* TODO git branch
        for (int i = 0; i < numBarrels; ++i) {
            if (barrels[i] == 0) {
                std::cout << "Slave " << digit + 1 << " drinks from a barrel: " << barrels[i] << '\n';
            }
        }
        for (int i = 0; i < numSlaves; ++i) {
            std::cout << "Slave " << i + 1 << " live? (1-yes, 0-nope): ";
            int alive;
            while (true) {
            std::cin >> alive;
            if (std::cin.fail() || alive != 1 || alive != 0) {
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
            if (alive == 0) {
                slaves[i] = digit;
            }
        }*/
        // day 1 
        for(size_t i = 0; i < numSlaves; ++i){
            if(toxic[i] == '0') slaves[i] == 0;
        }
        //day 2 
        for(size_t i = 0; i < numSlaves; ++i){
            if(toxic[i] == '1') slaves[i] == 1;
        }
        //final
        for(size_t i = 0; i < numSlaves; ++i){
            if(toxic[i] == -1) slaves[i] == 2;
        }

        /*bool allDead = true;
        for (int i = 0; i < numSlaves; ++i) {
            if (slaves[i] == -1) {
                allDead = false;
                break;
            }
        }
        if (allDead) {
            break;
        }*/
    }

    int number  = 0;
    for(size_t i = 0; i < numSlaves; ++i){
        if(slaves[i] == -1) slaves[i] == 2;
        number += slaves[i] * 10 * (i + 1);
    }

    return slaves == (toxic);
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
int main(){
    int numBarrels = 240;
    int numSlaves = 5;
    int barrels[numBarrels];
    int number = 0;
    int toxic = 0;
    std::cout  << "Enter the toxic barrel : ";
    while (true) {
            std::cin >> number;
            if (std::cin.fail() || number <= 0 || number > 240) {
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
    std::string toxicIN3 = toTernary(toxic);


    for (int i = 0; i < numBarrels; ++i) {
        std::string temp = toTernary(i + 1);
        barrels[i] = std::stoi(temp);
    }
    std::string slaves(numSlaves, -1);

    //int number = findingBarrel(slaves, barrels, toxicIN3);
    //std::cout << "The number of the poisoned barrel: " << number;
    
    std::cout << "Result: " << findingBarrel << " berrel - " << toxic;

    return 0;
}

