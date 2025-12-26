#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

int best;
vector<int> wth;

void Gen(int lvl, int n, int places, int cost, vector<int>& cur) {
    if (lvl > n) {
        if (cost < best) {
            best = cost;
            wth = cur;
            cout << "best = " << best << endl;
            for (auto& x : wth)
                cout << " " << x;
            cout << endl;
        }
    } else {
        for (int i = 1; i <= places; i++) {
            cur[lvl] = (cur[lvl - 1] + i - 1) % places + 1;
            int p = lvl - 1;
            while (cur[p] >= cur[lvl])
                --p;
            Gen(lvl + 1, n, places, cost + lvl - p, cur);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, places;
    while (cin >> n >> places) {
        best = Inf;
        vector cur(n + 1, 0);
        Gen(1, n, places, 0, cur);
    }
    return 0;
}