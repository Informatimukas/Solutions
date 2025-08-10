#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxv = 35;
constexpr int mod = 1000000007;

int Solve(int s, int& k, const vector<int>& my) {
    if (k == 0) return 1;
    if (s < Maxv && 1ll << (s - 1) <= k) {
        k -= 1ll << (s - 1);
        return my[s];
    }
    int res = s;
    k--;
    for (int i = 1; i < s && k > 0; i++)
        res = static_cast<ll>(res) * Solve(i, k, my) % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> my(Maxv), all(Maxv);
    my[1] = all[1] = 1;
    for (int i = 2; i < Maxv; i++) {
        my[i] = static_cast<ll>(i) * all[i - 1] % mod;
        all[i] = static_cast<ll>(my[i]) * all[i - 1] % mod;
    }
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        set<int> S;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            S.insert(x);
        }
        int res = 1;
        for (auto& el : S)
            res = static_cast<ll>(res) * Solve(el, k, my) % mod;
        cout << res << "\n";
    }
    return 0;
}
