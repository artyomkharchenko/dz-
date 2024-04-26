#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"

using namespace std;

pair<int, int> parser(const string& f) {
    ifstream inputFile(f);
    if (!inputFile.is_open()) {
        cout << "Не удалось открыть файл " << f << endl;
        return {-1, -1};
    }

    int n, c;
    inputFile >> n >> c;

    inputFile.close();
    return {n, c};
}
