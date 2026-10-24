#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using llll = pair<ll, ll>;

constexpr int Maxd = 10;

void Add(vector<llll>& BIT, int x, const llll& add) {
    for (int i = x + 1; i < BIT.size(); i += i & -i) {
        BIT[i].first += add.first;
        BIT[i].second += add.second;
    }
}

ll Get(const vector<llll>& BIT, int x) {
    llll res;
    for (int i = x + 1; i > 0; i -= i & -i) {
        res.first += BIT[i].first;
        res.second += BIT[i].second;
    }
    return res.first + res.second * x;
}

int Get(const vector<array<int, Maxd>>& nxt, int cur, const string& s) {
    for (int i = 0; i < s.length(); i++)
        cur = nxt[cur][s[i] - '0'];
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<array<int, Maxd>> nxt(n + 1);
        string s;
        cin >> s;
        ranges::fill(nxt[n], n);
        for (int i = n - 1; i >= 0; i--) {
            ranges::copy(nxt[i + 1], nxt[i].begin());
            nxt[i][s[i] - '0'] = i;
        }
        vector<llll> BIT(n + 1);
        for (int i = 0; i < n; i++) {
            int bad = Get(nxt, i, "2025");
            int good = Get(nxt, i, "2026");
            if (good <= bad)
                Add(BIT, i, {n, -1});
            else {
                Add(BIT, i, {bad, -1});
                Add(BIT, bad, {-bad, 1});
                int tims = n - good;
                Add(BIT, i, {tims, 0});
                Add(BIT, good, {-tims, 0});
                Add(BIT, good, {n, -1});
            }
        }
        for (int i = 0; i < n; i++)
            cout << Get(BIT, i) << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
