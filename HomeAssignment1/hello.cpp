#include "hello.h"
#include <iostream>

void myproject::sayHello() {
    std::cout<<"Чтобы выйти из цикла напишите '-'\n";
    while (true)
    {
        std::string word;
        std::cout << "Напишите слово: ";
        std::cin >> word ;
        if (word == "-"){
            break;
        }
        std::cout << "Hello, "; 
        std::cout << word << std::endl;
    }
}