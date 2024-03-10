#include "solver.hpp"
#include <iostream>
#include <cmath>

double Solver::calculateDistance(const std::pair<double, double>& a, const std::pair<double, double>& b) {
    return std::sqrt(std::pow(a.first - b.first, 2) + std::pow(a.second - b.second, 2));
}

double LocalSearchSolver::solve(const std::vector<std::pair<double, double>>& points) {
    int n = points.size();
    std::vector<int> path(n);
    for (int i = 0; i < n; ++i) {
        path[i] = i;
    }

    double best_distance = calculatePathLength(path, points);

    bool improved = true;
    while (improved) {
        improved = false;
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                std::swap(path[i], path[j]);
                double new_distance = calculatePathLength(path, points);
                if (new_distance < best_distance) {
                    best_distance = new_distance;
                    improved = true;
                } else {
                    std::swap(path[i], path[j]); 
                }
            }
        }
    }

    std::cout << "Optimal path: ";
    for (int i = 0; i < n; ++i) {
        std::cout << path[i] << " -> ";
    }
    std::cout << path[0] << std::endl;

    return best_distance;
}

double LocalSearchSolver::calculatePathLength(const std::vector<int>& path, const std::vector<std::pair<double, double>>& points) {
    double length = 0;
    int n = path.size();
    for (int i = 0; i < n - 1; ++i) {
        length += calculateDistance(points[path[i]], points[path[i + 1]]);
    }
    length += calculateDistance(points[path.back()], points[path.front()]);
    return length;
}
