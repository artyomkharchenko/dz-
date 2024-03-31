#include "solver.h"
pair<int, vector<bool>> kg(const vector<Item>& i, int c, int pS, int g) {
        srand(time(nullptr));

        pair<int, vector<bool>> bs;
        int bv = 0;

        for (int gen = 0; gen < g; ++gen) {
            vector<pair<int, vector<bool>>> p(pS);
            ip(p, i.size());

            for (int a = 0; a < pS; ++a) {
                int v = 0, w = 0;
                for (int b = 0; b < i.size(); ++b) {
                    if (p[a].second[b]) {
                        v += i[b].value;
                        w += i[b].weight;
                    }
                }

                if (w <= c && v > bv) {
                    bs = p[a];
                    bv = v;
                }
            }
        }

        return bs;
    }
void ip(vector<pair<int, vector<bool>>>& p, int s) {
        for (auto& ind : p) {
            ind.second.resize(s);
            for (int i = 0; i < s; ++i) {
                ind.second[i] = rand() % 2 == 1;
            }
        }
    }
}