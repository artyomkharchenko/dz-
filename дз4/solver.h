#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include "Item.h"

class Solver {
public:
    static std::pair<int, std::vector<bool>> knapsackBranchAndBound(int W, std::vector<Item>& items);

private:
    static int knapsackBound(int n, int W, int weightSoFar, int valueSoFar, std::vector<Item>& items);
    static bool compareByRatio(const Item &a, const Item &b);
};

#endif 
