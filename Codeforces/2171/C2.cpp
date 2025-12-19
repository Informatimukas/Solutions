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
        array<vector<int>, 2> P;
        int res = 0;
        for (auto& V : P) {
            V.resize(n);
            for (auto& x : V) {
                cin >> x;
                res ^= x;
            }
        }
        if (!res)
            cout << "Tie\n";
        else {
            int cur = 20;
            while (!(res & 1 << cur))
                --cur;
            int lst = n - 1;
            while ((P[0][lst] & 1 << cur) == (P[1][lst] & 1 << cur))
                --lst;
            cout << (lst % 2 ? "Mai" : "Ajisai") << "\n";
        }
    }
    return 0;
}
