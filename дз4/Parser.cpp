#include "Parser.h"
#include <fstream>
#include <iostream>

std::pair<int, int> Parser::parse(const std::string& filename) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file " << filename << std::endl;
        return {-1, -1};
    }

    int n, c;
    inputFile >> n >> c;
    inputFile.close();

    return {n, c};
}
