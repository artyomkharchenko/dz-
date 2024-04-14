
#ifndef PARSER_H
#define PARSER_H

#include "Graph.h"
#include <string>

class Parser {
public:
    static Graph parseGraph(const std::string& filename);
};

#endif 