#include "Solver.h"
#include <algorithm>
#include <queue>

int Solver::knapsackBound(int n, int W, int weightSoFar, int valueSoFar, std::vector<Item>& items) {
    if (weightSoFar >= W) return 0;

    int profitBound = valueSoFar;
    int j = n;
    int totalWeight = weightSoFar;

    while (j < items.size() && totalWeight + items[j].w <= W) {
        totalWeight += items[j].w;
        profitBound += items[j].v;
        j++;
    }

    if (j < items.size()) {
        profitBound += (W - totalWeight) * (static_cast<double>(items[j].v) / items[j].w);
    }

    return profitBound;
}

bool Solver::compareByRatio(const Item &a, const Item &b) {
    double ratio1 = static_cast<double>(a.v) / a.w;
    double ratio2 = static_cast<double>(b.v) / b.w;
    return ratio1 > ratio2;
}

std::pair<int, std::vector<bool>> Solver::knapsackBranchAndBound(int W, std::vector<Item>& items) {
        sort(items.begin(), items.end(), compareByRatio);

    queue<Node> Q;
    Node u, v;
    u.level = -1;
    u.profit = u.weight = 0;
    u.included = vector<bool>(items.size(), false);
    Q.push(u);
    int maxProfit = 0;
    vector<bool> itemsTaken;

    while (!Q.empty()) {
        u = Q.front();
        Q.pop();

        if (u.level == -1) {
            v.level = 0;
        }
        if (u.level == items.size() - 1) {
            continue;
        }
        
        v.level = u.level + 1;
        v.weight = u.weight + items[v.level].w;
        v.profit = u.profit + items[v.level].v;
        v.included = u.included;
        v.included[v.level] = true;

        if (v.weight <= W && v.profit > maxProfit) {
            maxProfit = v.profit;
            itemsTaken = v.included;
        }

        v.bound = knapsackBound(v.level, W, v.weight, v.profit, items);
        if (v.bound > maxProfit) {
            Q.push(v);
        }

        v.weight = u.weight;
        v.profit = u.profit;
        v.included = u.included;
        v.bound = knapsackBound(v.level, W, v.weight, v.profit, items);
        if (v.bound > maxProfit) {
            Q.push(v);
        }
    }

    return make_pair(maxProfit, itemsTaken);
}
