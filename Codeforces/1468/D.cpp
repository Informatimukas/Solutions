#include <bits/stdc++.h>
using namespace std;

bool Solve(const vector<int>& s, int lim, int x, int cnt) {
    if (x == cnt + 1 && s[0] != 1)
        return false;
    for (int i = 0; i < x; i++)
        if (s[i] + x - i > lim)
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
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        int lim = a < b ? b - 1: n - b;
        int cnt = abs(a - b) - 1;
        vector<int> s(m);
        for (auto& x : s)
            cin >> x;
        ranges::sort(s);
        int lef = 1, rig = min(static_cast<int>(s.size()), cnt);
        while (lef <= rig) {
            int m = (lef + rig) / 2;
            if (Solve(s, lim, m, cnt))
                lef = m + 1;
            else rig = m - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}