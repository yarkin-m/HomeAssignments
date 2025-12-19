/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 2b
 */
#include "rpn.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "RPN Calculator\n";
    std::cout << "Enter expression (or 'quit' to exit):\n";
    
    std::string input;
    while (std::getline(std::cin, input)) {
        if (input == "quit" || input == "exit") break;
        
        try {
            double result = evaluateRPN(input);
            std::cout << "Result: " << result << "\n";
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
        
        std::cout << "> ";
    }
    
    return 0;
}