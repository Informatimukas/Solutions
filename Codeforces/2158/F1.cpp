#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int getSize(int n) {
    if (n % 2)
        return n * (n + 1) / 2;
    return n * n / 2 + 1;
}

void Visit(int v, vector<set<int>>& neigh, vector<int>& seq) {
    while (!neigh[v].empty()) {
        int u = *neigh[v].begin();
        neigh[v].erase(u);
        neigh[u].erase(v);
        Visit(u, neigh, seq);
    }
    seq.push_back(v);
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
        int s = 1;
        while (getSize(s) < n - 1)
            ++s;
        vector res(s, 1ll);
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < i; j++)
                res[i] *= 2;
            for (int j = 0; j < s - i - 1; j++)
                res[i] *= 3;
        }
        vector<set<int>> neigh(s);
        for (int i = 0; i < s; i++)
            for (int j = 0; j < s; j++)
                if (s % 2 == 0 && min(i, j) % 2 == 0 &&
                    max(i, j) == min(i, j) + 1 &&
                    min(i, j) != 0) ;
                else neigh[i].insert(j);
        vector<int> seq;
        Visit(0, neigh, seq);
        for (int i = 0; i < n; i++)
            cout << res[seq[i]] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
