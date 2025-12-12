<<<<<<< HEAD
#include "reverse.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc == 3) {
        std::string inputFile = argv[1];
        std::string outputFile = argv[2];
        
        reverseFile(inputFile, outputFile);
    } 
    else if (argc == 1) {
        std::string inputFile = "input.bin";
        std::string outputFile = "output.bin";
        
        reverseFile(inputFile, outputFile);
    } 
    else {
        std::cout << "Usage: " << argv[0] << " [input_file] [output_file]" << std::endl;
        std::cout << "If no arguments provided, uses default: input.bin -> output.bin" << std::endl;
        return 1;
    }
    
    return 0;
}
=======
#include "reverse.h"
#include <iostream>
int main(int argc, char* argv[]) {
    if (argc == 3) {
        std::string inputFile = argv[1];
        std::string outputFile = argv[2];
        reverseFile(inputFile, outputFile);
    } 
    else if (argc == 1) {
        std::string inputFile = "input.bin";
        std::string outputFile = "output.bin";
        reverseFile(inputFile, outputFile);
    } 
    else {
        std::cout << "Usage: " << argv[0] << " [input_file] [output_file]" << std::endl;
        std::cout << "If no arguments provided, uses default: input.bin -> output.bin" << std::endl;
        return 1;
    }
    return 0;
}
>>>>>>> c13282286ece2ce377209c916f47f8aecf37b899
