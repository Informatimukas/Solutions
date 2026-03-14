#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

bool isSubset(const string& s1, const string& s2) {
    for (int i = 0; i < s2.length(); i++)
        if (s2[i] == '1' && s1[i] == '0')
            return false;
    return true;
}

int getPar(vector<int>& par, int x) { return par[x] == x ? x : par[x] = getPar(par, par[x]); }

bool unionSet(vector<int>& par, vector<int>& siz, int a, int b) {
    a = getPar(par, a);
    b = getPar(par, b);
    if (a == b)
        return false;
    if (siz[a] < siz[b])
        swap(a, b);
    siz[a] += siz[b];
    par[b] = a;
    return true;
}

void Solve(const vector<string>& B, const vector<ii>& seq) {
    vector neigh(seq.size(), vector<int>());
    vector<int> par(seq.size()), siz(seq.size(), 1);
    iota(par.begin(), par.end(), 0);
    int got = 0;
    for (int i = 1; i < seq.size(); i++)
        for (int j = i - 1; j >= 0; j--) {
            int v = seq[j].second;
            int u = seq[i].second;
            if (isSubset(B[v], B[u]) && unionSet(par, siz, v, u)) {
                got++;
                neigh[v].push_back(u);
            }
        }
    if (got != seq.size() - 1) {
        cout << "No\n";
        return;
    }
    vector real(seq.size(), string(seq.size(), '0'));
    for (int i = seq.size() - 1; i >= 0; i--) {
        int v = seq[i].second;
        real[v].resize(seq.size());
        real[v][v] = '1';
        for (auto u : neigh[v])
            for (int j = 0; j < seq.size(); j++)
                if (real[u][j] == '1')
                    real[v][j] = '1';
    }
    for (int i = 0; i < seq.size(); i++)
        if (B[i] != real[i]) {
            cout << "No\n";
            return;
        }
    cout << "Yes\n";
    for (int i = 0; i < seq.size(); i++)
        for (auto u : neigh[i])
            cout << i + 1 << " " << u + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<string> B(n);
        for (auto& x : B)
            cin >> x;
        vector<ii> seq(n);
        for (int i = 0; i < n; i++) {
            seq[i].second = i;
            seq[i].first = 0;
            for (int j = 0; j < n; j++)
                seq[i].first += B[i][j] == '1';
        }
        ranges::sort(seq, greater());
        Solve(B, seq);
    }
    return 0;
}
