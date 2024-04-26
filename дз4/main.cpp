#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "parser.h"
#include "solver.h"
#include "Item.h"

using namespace std;

int main() {
    string f = "input.txt";
    auto [n, c] = parser(f);
    if (n == -1 || c == -1) {
        return 1;
    }

    vector<Item> items(n);
    ifstream inputFile(f);
    inputFile >> n >> c;
    for (int i = 0; i < n; i++) {
        inputFile >> items[i].v >> items[i].w; 
    }
    inputFile.close();

    auto result = solver(c, items, n);
    double maxv = result.first;
    vector<int> si = result.second;

    int sw = 0;
    for (int i : si) {
        sw += items[i].w; 
    }

    cout << maxv << " " << c - sw << endl; 
    for (int i = 0; i < n; ++i) {
        cout << (find(si.begin(), si.end(), i) != si.end() ? 1 : 0) << " ";
    }
    cout << endl;

    return 0;
}
