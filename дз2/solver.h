#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <cstdlib>
#include <ctime>
#include "item.h"

class Solver {
public:
    static pair<int, vector<bool>> kg(const vector<Item>& i, int c, int pS, int g) ;
private:
    static void ip(vector<pair<int, vector<bool>>>& p, int s) ;
};
#endif