#include <iostream>
#include <vector>
#include "parser.h"
#include "solver.h"

using namespace std;

int main() {
    string iF = "input.txt";
    int pS = 100;
    int g = 1000;
    pair<int, vector<Item>> d = Parser::pi(iF);
    int c = d.first;
    const vector<Item>& i = d.second;
    pair<int, vector<bool>> s = Solver::kg(i, c, pS, g);
    int rC = c;
    int tV = 0;
    for (int j = 0; j < i.size(); ++j) {
        if (s.second[j]) {
            rC -= i[j].weight;
            tV += i[j].value;
        }
    }

    cout << tV << " " << rC << endl;
    for (bool t : s.second) {
        cout << t << " ";
    }
    cout << endl;

    return 0;
}