#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>
#include <utility>

class Parser {
public:
    virtual std::vector<std::pair<double, double>> read(const std::string& filename, int& numPoints) = 0;
};

class FileReader : public Parser {
public:
    std::vector<std::pair<double, double>> read(const std::string& filename, int& numPoints) override;
};

#endif 