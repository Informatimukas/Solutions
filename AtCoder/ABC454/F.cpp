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
        int n, m;
        cin >> n >> m;
        int lst = 0;
        vector<int> seq(n + 1);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            int dif = (a - lst + m) % m;
            seq[i] = dif;
            lst = a;
        }
        seq[n] = (m - lst) % m;
        vector<ll> sums;
        ll curlef = 0, currig = 0;
        int l = 0, r = n;
        while (l < r) {
            ll val = (seq[l] + seq[r]) % m;
            sums.push_back(val);
            curlef += val;
            l++;
            r--;
        }
        ranges::sort(sums);
        ll res = curlef;
        for (int i = sums.size() - 1; i >= 0; i--) {
            curlef -= sums[i];
            currig += m - sums[i];
            res = min(res, max(curlef, currig));
        }
        cout << res << "\n";
    }
    return 0;
}
