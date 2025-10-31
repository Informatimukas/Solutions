#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        map<int, set<int>> M;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            M[0].insert(i);
        ll lst = 0;
        for (int i = 1; i <= n; i++) {
            ll b;
            cin >> b;
            int nd = i - (b - lst);
            int val = *M[nd].begin();
            M[nd].erase(val);
            M[i].insert(val);
            lst = b;
            cout << val << (i + 1 <= n ? ' ' : '\n');
        }
    }
    return 0;
}
