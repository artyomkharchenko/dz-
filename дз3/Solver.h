#ifndef SOLVER_H
#define SOLVER_H

#include "Graph.h"
#include <vector>

class Solver {
public:
    static std::vector<int> gcol(const Graph& graph);
};

#endif 
