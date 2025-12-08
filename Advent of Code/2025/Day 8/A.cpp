#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ii = pair<int, int>;
using ldii = pair<ld, ii>;

constexpr int Maxc = 1000;

struct unionSet {
    vector<int> par, siz;
    unionSet(int n): par(n), siz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    bool Union(int a, int b) {
        a = getPar(a), b = getPar(b);
        if (a == b)
            return false;
        if (siz[a] < siz[b])
            swap(a, b);
        siz[a] += siz[b];
        par[b] = a;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    vector<array<int, 3>> seq;
    string s;
    while (getline(cin, s)) {
        for (auto& ch : s)
            if (ch == ',')
                ch = ' ';
        stringstream ss(s);
        int x, y, z;
        ss >> x >> y >> z;
        seq.push_back({x, y, z});
    }
    vector<ldii> E;
    for (int i = 0; i < seq.size(); i++)
        for (int j = i + 1; j < seq.size(); j++) {
            ld sum = 0;
            for (int k = 0; k < seq[i].size(); k++)
                sum += static_cast<ld>(seq[j][k] - seq[i][k]) * (seq[j][k] - seq[i][k]);
            sum = sqrt(sum);
            E.push_back({sum, {i, j}});
        }
    ranges::sort(E);
    unionSet US(seq.size());
    for (int i = 0; i < E.size() && i < Maxc; i++) {
        auto [a, b] = E[i].second;
        US.Union(a, b);
    }
    vector<int> comp;
    for (int i = 0; i < seq.size(); i++)
        if (US.getPar(i) == i)
            comp.push_back(US.siz[i]);
    ranges::sort(comp, greater());
    int res = comp[0] * comp[1] * comp[2];
    cout << res << endl;
    return 0;
}