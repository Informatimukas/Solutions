#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Maxn = 100005;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<unordered_set<ll, custom_hash>> S(Maxn);

void Insert(int x, int y) {
    S[x].insert(y);
}

void Erase(int x, int y) {
    S[x].erase(y);
}

bool Contains(int x, int y) {
    return S[x].contains(y);
}

constexpr int Maxp = 320;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> byX(Maxn);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        byX[x].push_back(y);
        Insert(x, y);
    }
    ll res = 0;
    for (int i = 0; i < Maxn; i++)
        if (byX[i].size() <= Maxp) {
            ranges::sort(byX[i]);
            for (int a = 0; a < byX[i].size(); a++)
                for (int b = a + 1; b < byX[i].size(); b++) {
                    int y1 = byX[i][a], y2 = byX[i][b];
                    int d = y2 - y1;
                    if (i - d < 0 && i + d >= Maxn)
                        break;
                    if (i - d >= 0 && Contains(i - d, y1) && Contains(i - d, y2))
                        ++res;
                    if (i + d < Maxn && Contains(i + d, y1) && Contains(i + d, y2))
                        ++res;
                }
            for (auto y : byX[i])
                Erase(i, y);
            byX[i].clear();
        }
    vector<vector<int>> byY(Maxn);
    for (int i = 0; i < Maxn; i++)
        for (auto y : byX[i])
            byY[y].push_back(i);
    for (int i = 0; i < Maxn; i++) {
        ranges::sort(byY[i]);
        for (int a = 0; a < byY[i].size(); a++)
            for (int b = a + 1; b < byY[i].size(); b++) {
                int x1 = byY[i][a], x2 = byY[i][b];
                int d = x2 - x1;
                if (i - d < 0)
                    break;
                if (Contains(x1, i - d) && Contains(x2, i - d))
                    ++res;
            }
    }
    cout << res << "\n";
    return 0;
}
