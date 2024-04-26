#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <utility>
#include "Item.h"

std::pair<double, std::vector<int>> solver(int c, const std::vector<Item>& items, int n);

#endif
