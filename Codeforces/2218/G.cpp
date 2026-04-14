#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 676767677;

bool hasNeighbours(const vector<int>& b, int ind, int val) {
    return ind > 0 && b[ind - 1] < val || ind + 1 < b.size() && b[ind + 1] < val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> b(n);
        for (auto& x : b)
            cin >> x;
        vector cnt(m, 0ll);
        for (int i = 0; i < n; i++)
            cnt[b[i]]++;
        ll sum = cnt[0];
        for (int j = 1; j < m; j++) {
            ll nsum = sum + cnt[j];
            cnt[j] = sum;
            sum = nsum;
        }
        ll res = 1;
        for (int i = 0; i < n; i++)
            if (b[i] > 0) {
                if (!hasNeighbours(b, i, b[i])) {
                    res = 0;
                    break;
                }
                if (hasNeighbours(b, i, b[i] - 1))
                    res = res * (cnt[b[i]] - cnt[b[i] - 1]) % mod;
                else res = res * cnt[b[i]] % mod;
            }
        cout << res << "\n";
    }
    return 0;
}
