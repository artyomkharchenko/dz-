#include <iostream>
#include <vector>
#include "Item.h"
#include "Parser.h"
#include "Solver.h"

void printItems(const std::vector<bool>& included) {
    for (bool item : included) {
        std::cout << (item ? 1 : 0) << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::string filename = "input.txt";
    auto [n, c] = Parser::parse(filename);

    if (n == -1 || c == -1) {
        return 1;
    }

    std::vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        std::cin >> items[i].v >> items[i].w;
    }

    auto result = Solver::knapsackBranchAndBound(c, items);
    int maxProfit = result.first;
    std::vector<bool> itemsTaken = result.second;
    int remainingSpace = c;

    for (int i = 0; i < n; ++i) {
        if (itemsTaken[i]) {
            remainingSpace -= items[i].w;
        }
    }

    std::cout << maxProfit << " " << remainingSpace << std::endl;
    printItems(itemsTaken);

    return 0;
}
