#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> res(n);
    int cur = 0;
    while (cur < n * n) {
        for (int i = 0; i < n; i++)
            res[i].push_back(++cur);
        for (int i = n - 1; i >= 0; i--)
            res[i].push_back(++cur);
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << (j + 1 < res[i].size() ? ' ' : '\n');
    return 0;
}
