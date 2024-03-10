#ifndef SOLVER_HPP
#define SOLVER_HPP

#include <vector>
#include <utility>

class Solver {
public:
    virtual double solve(const std::vector<std::pair<double, double>>& points) = 0;
    double calculateDistance(const std::pair<double, double>& a, const std::pair<double, double>& b);
};

class LocalSearchSolver : public Solver {
public:
    double solve(const std::vector<std::pair<double, double>>& points) override;
private:
    double calculatePathLength(const std::vector<int>& path, const std::vector<std::pair<double, double>>& points);
};

#endif 