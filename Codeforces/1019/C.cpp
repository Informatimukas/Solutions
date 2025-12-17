#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector rem(n + 1, false);
    vector neigh(n + 1, vector<int>()), rneigh(n + 1, vector<int>());
    vector res(n + 1, false);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        neigh[a].push_back(b);
        rneigh[b].push_back(a);
    }
    vector<int> seq;
    for (int i = 1; i <= n; i++)
        if (!rem[i]) {
            seq.push_back(i);
            rem[i] = true;
            for (auto& u : neigh[i])
                rem[u] = true;
        }
    vector<int> ans;
    for (auto& v : seq | views::reverse)
        if (ranges::all_of(rneigh[v], [&](int u) { return !res[u]; })) {
            res[v] = true;
            ans.push_back(v);
        }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
    return 0;
}