#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "item.h"

using namespace std;
class Parser {
public:
    static pair<int, vector<Item>> pi(const string& fN); 
};
#endif