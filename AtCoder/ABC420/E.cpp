#include <bits/stdc++.h>
using namespace std;

int getPar(int x, vector<int>& par) { return par[x] == x? x: par[x] = getPar(par[x], par); }

void unionSet(int a, int b, vector<int>& par, vector<int>& siz, vector<int>& blacks) {
    a = getPar(a, par);
    b = getPar(b, par);
    if (a == b) return;
    if (siz[a] < siz[b]) swap(a, b);
    siz[a] += siz[b];
    blacks[a] += blacks[b];
    par[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> par(n + 1);
    iota(par.begin(), par.end(), 0);
    vector siz(n + 1, 1);
    vector blacks(n + 1, 0);
    vector my(n + 1, 0);
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int u, v;
            cin >> u >> v;
            unionSet(u, v, par, siz, blacks);
        } else if (typ == 2) {
            int v;
            cin >> v;
            int root = getPar(v, par);
            blacks[root] -= my[v];
            my[v] = !my[v];
            blacks[root] += my[v];
        } else {
            int v;
            cin >> v;
            cout << (blacks[getPar(v, par)] ? "Yes" : "No") << "\n";
        }
    }
    return 0;
}
