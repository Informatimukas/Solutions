#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxb = 35;
constexpr ll Inf = 1000000000000000000ll;

ll getMask(ll a, ll need, ll extra) {
    if (extra > 0) need |= 1ll << extra - 1;
    for (int i = Maxb - 1; i >= 0; i--)
        if ((a & 1ll << i) != (need & 1ll << i)) {
            if (a & 1ll << i)
                need ^= 1ll << i;
            else return need;
        }
    return need;
}

ll solveAll(const vector<ll>& a, vector<ll>& b) {
    vector num(b.size(), vector<ll>(Maxb));
    for (int i = 0; i < b.size(); i++) {
        ll need = 0;
        if (i < a.size()) need |= a[i];
        if (i) need |= a[i - 1];
        for (int j = 0; j < Maxb; j++)
            num[i][j] = getMask(b[i], need, j);
    }
    vector dp(b.size(), vector(Maxb, Inf));
    for (int j = 0; j < Maxb; j++)
        dp[0][j] = num[0][j] - b[0];
    for (int i = 1; i < b.size(); i++)
        for (int j = 0; j < Maxb; j++)
            for (int k = 0; k < Maxb; k++)
                if ((num[i - 1][j] & num[i][k]) == a[i - 1])
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + num[i][k] - b[i]);
    auto res = *ranges::min_element(dp.back());
    return res >= Inf ? -1 : res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n - 1);
        for (auto& x : a)
            cin >> x;
        vector<ll> b(n);
        for (auto& x : b)
            cin >> x;
        cout << solveAll(a, b) << endl;
    }
    return 0;
}