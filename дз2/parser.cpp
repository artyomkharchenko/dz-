#include "parser.h"
pair<int, vector<Item>> pi(const string& fN) {
        ifstream f(fN);
        if (!f.is_open()) {
            cerr << "Ошибка открытия файла " << fN << endl;
            exit(1);
        }
        int n, c;
        f >> n >> c;
        vector<Item> i(n);
        for (int j = 0; j < n; ++j) {
            f >> i[j].value >> i[j].weight;
        }
        f.close();
        return make_pair(c, i);
    }