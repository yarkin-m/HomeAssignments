/*
    Yarkin Makar
    st141442@student.spbu.ru
    Assignment 2b
*/
#include "rpn.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "=== RPN Calculator ===\n";
    std::cout << "Enter expression in Reverse Polish Notation\n";
    std::cout << "Example: 3 4 + 2 *\n";
    std::cout << "Enter 'quit' to exit\n\n";
    
    while (true) {
        std::cout << "> ";
        std::string input;
        std::getline(std::cin, input);
        
        if (input == "quit" || input == "exit") {
            break;
        }
        
        if (input.empty()) {
            continue;
        }
        
        try {
            double result = evaluateRPN(input);
            std::cout << "Result: " << result << "\n\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n\n";
        }
    }
    
    std::cout << "Goodbye!\n";
    return 0;
}