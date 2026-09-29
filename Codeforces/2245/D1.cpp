#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> neigh(2 * n);
        vector<int> in(2 * n);
        vector<int> my(2 * n);
        for (int i = 0; i < m; i++) {
            int o, a, b;
            cin >> o >> a >> b;
            a--; b--;
            a *= 2; b *= 2;
            if (o == 1) {
                neigh[a + 1].push_back(b);
                neigh[b + 1].push_back(a);
                in[b]++; in[a]++;
            } else {
                neigh[b].push_back(a + 1);
                neigh[a].push_back(b + 1);
                in[a + 1]++;
                in[b + 1]++;
            }
        }
        vector<int> seq;
        for (int i = 0; i < 2 * n; i++)
            if (in[i] == 0)
                seq.push_back(i);
        for (int i = 0; i < seq.size(); i++) {
            my[seq[i]] = i;
            for (auto u : neigh[seq[i]])
                if (--in[u] == 0)
                    seq.push_back(u);
        }
        if (seq.size() != 2 * n) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << my[2 * i] - my[2 * i + 1] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
