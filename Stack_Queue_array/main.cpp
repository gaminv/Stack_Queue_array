#include <iostream>
#include <string>
#include "StackArray.h"

bool isOperator(char c) {
    return c == '+' || c == '-' ;
}

int getPriority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    return 0;
}

std::string getPostfixFromInfix(const std::string& infix) {
    StackArray<char> operators(infix.length());
    std::string postfix = "";
    for (size_t i = 0; i < infix.length(); i++) {
        char c = infix[i];
        if (isdigit(c)) { 
            postfix += c;
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.isEmpty() && operators.top_() != '(') {
                postfix += operators.top_();
                operators.pop();
            }
            if (operators.isEmpty()) {
                throw std::runtime_error("Invalid expression: mismatched parentheses");
            }
            operators.pop(); 
        }
        else if (isOperator(c)) { 
            while (!operators.isEmpty() && operators.top_() != '(' && getPriority(operators.top_()) >= getPriority(c)) {
                postfix += operators.top_();
                operators.pop();
            }
            operators.push(c);
        }
        else {
            throw std::runtime_error("Invalid character in expression");
        }
    }
    while (!operators.isEmpty()) {
        if (operators.top_() == '(') {
            throw std::runtime_error("Invalid expression: mismatched parentheses");
        }
        postfix += operators.top_();
        operators.pop();
    }
    return postfix;
}

int main() {
    try
    {
        std::string infix = "2-(3+4)+5-6";
        std::string postfix = getPostfixFromInfix(infix);
        std::cout << "Infix: " << infix << std::endl;
        std::cout << "Postfix: " << postfix << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
   
    return 0;
}