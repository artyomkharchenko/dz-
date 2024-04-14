#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>
#include <string>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    int numv() const;
    const std::vector<std::set<int>>& getal() const;
private:
    int V; 
    std::vector<std::set<int>> adj; 
};

#endif 