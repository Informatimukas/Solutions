#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iii = pair<int, ii>;

struct UnionSet {
    vector<int> par, siz;
    UnionSet(int n): par(n), siz(n, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); }
    bool unionSet(int a, int b) {
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
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, a, b;
        cin >> n >> a >> b;
        cout << "Case #" << tc << ":";
        for (int i = 0; i < 2 * n - 1; i++)
            cout << " 1";
        cout << " " << b << "\n";
    }
    return 0;
}