#include "reverse.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
void reverseFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile, std::ios::binary | std::ios::ate);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << inputFile << std::endl;
        return;
    }
    std::streamsize size = inFile.tellg();
    std::cout << "File size: " << size << " bytes" << std::endl;
    if (size == 0) {
        std::cerr << "File is empty" << std::endl;
        inFile.close();
        std::ofstream outFile(outputFile, std::ios::binary);
        outFile.close();
        return;
    }
    inFile.seekg(0, std::ios::beg);
    std::vector<char> buffer(size);
    if (!inFile.read(buffer.data(), size)) {
        std::cerr << "Error reading file" << std::endl;
        inFile.close();
        return;
    }
    inFile.close();
    for (std::streamsize i = 0; i < size / 2; ++i) {
        std::swap(buffer[i], buffer[size - 1 - i]);
    }
    std::ofstream outFile(outputFile, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Error creating file: " << outputFile << std::endl;
        return;
    }
    outFile.write(buffer.data(), size);
    if (!outFile.good()) {
        std::cerr << "Error writing to file" << std::endl;
    }
    outFile.close();
    std::cout << "File successfully reversed and saved as: " << outputFile << std::endl;
}
