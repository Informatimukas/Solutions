#include <bits/stdc++.h>
using namespace std;

vector<int> Solve(const vector<int>& p, const vector<int>& d) {
    vector<int> q(p.size());
    for (int i = p.size() - 1; i >= 0; i--) {
        int n = p.size() - i;
        vector visited(n + 1, false);
        for (int j = i + 1; j < p.size(); j++)
            if (p[i] < p[j])
                visited[q[j]] = true;
        int lft = d[i], val = -1;
        for (int j = n; j > 0; j--) {
            lft -= visited[j];
            if (lft == 0) {
                val = j;
                break;
            }
        }
        if (val == -1)
            return {};
        q[i] = val;
        for (int j = i + 1; j < p.size(); j++)
            if (q[j] >= q[i])
                q[j]++;
    }
    return q;
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
        vector<int> p(n);
        for (auto& x : p)
            cin >> x;
        vector<int> d(n);
        for (auto& x : d)
            cin >> x;
        auto res = Solve(p, d);
        if (res.empty()) {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
