/*
 *   Yarkin Makar
 *   st141442@student.spbu.ru
 *   Assignment 2b
 */
#include "rpn.h"
#include <sstream>
#include <stack>
#include <string>
#include <stdexcept>
#include <cmath>

bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double applyOperation(double a, double b, const std::string& op) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") {
        if (b == 0) throw std::runtime_error("Division by zero");
        return a / b;
    }
    throw std::runtime_error("Unknown operator: " + op);
}

double evaluateRPN(const std::string& expression) {
    std::stack<double> stack;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token) {
        if (isOperator(token)) {
            if (stack.size() < 2) {
                throw std::runtime_error("Insufficient operands for operator: " + token);
            }
            
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
            
            double result = applyOperation(a, b, token);
            stack.push(result);
        } else {
            try {
                double num = std::stod(token);
                stack.push(num);
            } catch (const std::invalid_argument&) {
                throw std::runtime_error("Invalid token: " + token);
            }
        }
    }
    
    if (stack.size() != 1) {
        throw std::runtime_error("Invalid expression: stack has " + 
                                std::to_string(stack.size()) + " values left");
    }
    
    return stack.top();
}
