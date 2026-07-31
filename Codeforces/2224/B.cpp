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
        int n;
        cin >> n;
        multiset<int> all;
        set<int> S;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            all.insert(x);
        }
        S.insert(*all.rbegin());
        all.erase(prev(all.end()));
        int mx = *S.begin(), mex = 0;
        while (S.contains(mex))
            mex++;
        ll res = 0;
        for (int i = 0; i < n; i++) {
            res += mx + mex;
            if (all.contains(mex)) {
                all.erase(all.find(mex));
                S.insert(mex);
            }
            while (S.contains(mex))
                mex++;
        }
        cout << res << "\n";
    }
    return 0;
}
