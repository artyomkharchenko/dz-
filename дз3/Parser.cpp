#include "Parser.h"
#include <fstream>
#include <iostream>

Graph Parser::parseGraph(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        exit(1);
    }
    int V, E;
    file >> V >> E;
    Graph graph(V);
    int u, v;
    for (int i = 0; i < E; ++i) {
        file >> u >> v;
        graph.addEdge(u, v);
    }
    file.close();
    return graph;
}