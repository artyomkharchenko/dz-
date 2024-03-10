#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <utility>
#include <string>

class Database {
private:
    std::vector<std::pair<double, double>> points;
public:
    Database(const std::string& filename);
    void print_t() const;
    const std::vector<std::pair<double, double>>& getPoints() const;
};

#endif 
