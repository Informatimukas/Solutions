#include <bits/stdc++.h>
using namespace std;

bool Move(int from, int to, int tmp, int n, const vector<int>& a, vector<array<int, 3>>& res) {
    if (n == 0)
        return true;
    if (a[n] > n - 1)
        return false;
    if (!Move(from, tmp, to, n - 1 - a[n], a, res))
        return false;
    res.push_back({n, from, to});
    if (a[n] > 0) {
        if (!Move(tmp, from, to, n - 1 - a[n], a, res))
            return false;
        if (!Move(from, to, tmp, n - 1, a, res))
            return false;
    } else if (!Move(tmp, to, from, n - 1, a, res))
        return false;
    return true;
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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        vector<array<int, 3>> res;
        if (!Move(1, 3, 2, n, a, res)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << res.size() << "\n";
        for (auto& ans : res)
            cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
    }
    return 0;
}
