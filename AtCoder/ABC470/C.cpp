#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    set<int> S;
    int res = 0;
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int x;
            cin >> x;
            res ^= a[x];
            a[x]++;
            res ^= a[x];
            S.insert(x);
        } else {
            set<int> nS;
            for (auto ind : S) {
                res ^= a[ind];
                a[ind]--;
                res ^= a[ind];
                if (a[ind] > 0)
                    nS.insert(ind);
            }
            S = nS;
        }
        cout << res << "\n";
    }
    return 0;
}
