#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    set<int> S;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        S.insert(b);
    }
    vector<int> res;
    for (auto x : a)
        if (S.contains(x))
            res.push_back(x);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    return 0;
}
