#include <vector>
#include <algorithm>
#include "solver.h"
#include "Item.h"

using namespace std;

pair<double, vector<int>> solver(int c, const vector<Item>& items, int n) {
    vector<vector<double>> dp(n + 1, vector<double>(c + 1, 0.0));
    
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= c; ++w) {
            if (items[i - 1].w <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].w] + items[i - 1].v);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    double maxv = dp[n][c];
    vector<int> si;
    int w = c;
    for (int i = n; i > 0 && maxv > 0; --i) {
        if (maxv == dp[i - 1][w]) {
            continue;
        } else {
            si.push_back(i - 1);
            maxv -= items[i - 1].v;
            w -= items[i - 1].w;
        }
    }
    
    return make_pair(dp[n][c], si);
}
