#include "database.hpp"
#include "parser.hpp"
#include <iostream>

Database::Database(const std::string& filename) {
    FileReader reader;
    int numPoints;
    points = reader.read(filename, numPoints);
}

void Database::print_t() const {
    for (const auto& point : points) {
        std::cout << point.first << " " << point.second << std::endl;
    }
}

const std::vector<std::pair<double, double>>& Database::getPoints() const {
    return points;
}
