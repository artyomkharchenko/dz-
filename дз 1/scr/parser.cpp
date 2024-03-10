#include "parser.hpp"
#include <fstream>
#include <iostream>

std::vector<std::pair<double, double>> FileReader::read(const std::string& filename, int& numPoints) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file " << filename << std::endl;
        numPoints = 0;
        return {};
    }
    file >> numPoints;
    std::vector<std::pair<double, double>> points(numPoints);
    for (int i = 0; i < numPoints; ++i) {
        file >> points[i].first >> points[i].second;
    }
    file.close();
    return points;
}

