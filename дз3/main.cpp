
#include <iostream>
#include "Graph.h"
#include "Parser.h"
#include "Solver.h"

int main() {
    Graph graph = Parser::parseGraph("input.txt");
    std::vector<int> colors = Solver::gcol(graph);
    std::cout << "Coloring of vertices:" << std::endl;
    for (int i = 0; i < graph.numv(); ++i) {
        std::cout << "Vertex " << i << ": Color " << colors[i] << std::endl;
    }

    return 0;
}
