#include "Graph.h"

Graph::Graph(int vertices) : V(vertices), adj(vertices) {}

void Graph::addEdge(int u, int v) {
    adj[u].insert(v);
    adj[v].insert(u);
}

int Graph::numv() const {
    return V;
}

const std::vector<std::set<int>>& Graph::getal() const {
    return adj;
}