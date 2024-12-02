#include <iostream>
#include <limits>
#include <string>
#include "func_1.h"
#include "func_2.h"
#include "func_3.h"
#include "func_4.h"
#include "func_5.h"

void WhatISIt() {
    std::cout << "Here you can check the whole LR7.\n";
}

void Task_1(){

int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else {
                break;
            }
        }
        switch (choice) {
            case 1:
                ExplainTask1();
                break;
            case 2:
                AuthorInfo();
                break;
            case 3:
                InputValues1();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);

}

// TODO
void Task_2(){

int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else {
                break;
            }
        }
        switch (choice) {
            case 1:
                //ExplainTask2();
                break;
            case 2:
                AuthorInfo();
                break;
            case 3:
                //InputValue2();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);
}

void Task_3(){

int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else {
                break;
            }
        }
        
        switch (choice) {
            case 1:
            //ExplainTask3();
            break;
            case 2:
                AuthorInfo();
            break;
            case 3:
                //InputValue3();
            break;
            case 0:
                std::cout << "Exiting the program.\n";
            break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);

}

void Task_4(){

int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else {
                break;
            }
        }
        
        switch (choice) {
            case 1:
            //ExplainTask4();
            break;
            case 2:
                AuthorInfo();
            break;
            case 3:
                //InputValue4();
            break;
            case 0:
                std::cout << "Exiting the program.\n";
            break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);

}

void Task_5(){

int choice;
    do {
        DisplayMenuTask();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 3) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-3): ";
            } else {
                break;
            }
        }
        
        switch (choice) {
            case 1:
            //ExplainTask5();
            break;
            case 2:
                AuthorInfo();
            break;
            case 3:
                //InputValue5();
            break;
            case 0:
                std::cout << "Exiting the program.\n";
            break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);

}

void DisplayMenu() {
    std::cout << "--- Context menu ---\n"
              << "1. Here you can check the whole\n"
              << "2. Go to task-1\n"
              << "3. Go to task-2\n"
              << "4. Go to task-3\n"
              << "5. Go to task-4\n"
              << "6. Go to task-5\n"
              << "0. Exit\n"
              << "Choose an option: ";
}

int main() {
    
    int choice;
    do {
        DisplayMenu();
        while (true) {
            std::cin >> choice;
            if (std::cin.fail() || choice < 0 || choice > 4) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-4): ";
            } else if (std::cin.peek() != '\n') {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a valid option (0-4): ";
            } else {
                break;
            }
        }
        switch (choice) {
            case 1:
                WhatISIt();
                break;
            case 2:
                Task_1();
                break;
            case 3:
                Task_2();
                break;
                case 4:
                Task_3();
                case 5:
                Task_4();
                case 6:
                Task_5();
                break;
            case 0:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
        std::cout << '\n';
    } while (choice != 0);

    return 0;
}
