#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <utility>

class Parser {
public:
    static std::pair<int, int> parse(const std::string& filename);
};

#endif 
