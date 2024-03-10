#include <iostream>
#include "database.hpp"
#include "solver.hpp"

int main() {
    std::string filename = "input.txt";
    Database database(filename);
    
    std::cout << "Database:" << std::endl;
    database.print_t();
    
    const std::vector<std::pair<double, double>>& points = database.getPoints();

    if (points.empty()) {
        std::cout << "Error: No data available." << std::endl;
        return 1;
    }

    Solver* solver = new LocalSearchSolver();
    double distance = solver->solve(points);

    std::cout << "Optimal path distance: " << distance << std::endl;

    delete solver;

    return 0;
}
