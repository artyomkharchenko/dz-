
#include "Solver.h"
#include <vector>
#include <set>

std::vector<int> Solver::gcol(const Graph& graph) {
    std::vector<int> result(graph.numv(), -1); 
    for (int u = 0; u < graph.numv(); ++u) {
        std::set<int> usedColors; 
        for (int v : graph.getal()[u]) {
            if (result[v] != -1) {
                usedColors.insert(result[v]);
            }
        }
        int color = 0;
        for (int c : usedColors) {
            if (color != c) {
                break;
            }
            ++color;
        }
        result[u] = color;
    }
    return result;
}
