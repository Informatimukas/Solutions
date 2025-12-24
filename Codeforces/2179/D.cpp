#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int cur = (1 << n) - 1;
        vector<int> res;
        set<int> forb;
        res.push_back(cur);
        forb.insert(cur);
        for (int d = n; d >= 0; d--)
            for (int i = 0; i < 1 << n; i++)
                if (!forb.contains(i) && __builtin_popcount(cur & i) == d) {
                    res.push_back(i);
                    forb.insert(i);
                    cur &= i;
                }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
