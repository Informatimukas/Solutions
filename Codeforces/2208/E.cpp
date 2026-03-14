#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int mod = 998244353;

int getSum(const vector<int>& a) {
    int tot = 0;
    for (auto x : a)
        tot = (tot + x) % mod;
    return tot;
}

vector<int> Solve(const vector<int>& a, int l, int r) {
    if (l > r) {
        vector res(a.size() + 1, 0);
        res[0] = 1;
        return res;
    }
    if (l == r) {
        vector res(a.size() + 1, 0);
        if (a[l] == l - 1 || a[l] == -1)
            res[1] = 1;
        return res;
    }
    for (int i = l; i <= r; i++)
        if (a[i] != -1 && a[i] < l - 1)
            return vector(a.size() + 1, 0);
    if (a[r] == -1) {
        auto old = Solve(a, l, r - 1);
        int all = 0;
        vector nw(a.size() + 1, 0);
        for (int i = a.size(); i > 0; i--) {
            all = (all + old[i - 1]) % mod;
            nw[i] = all;
        }
        return nw;
    }
    if (a[r] >= r)
        return vector(a.size() + 1, 0);
    int ways = getSum(Solve(a, a[r] + 1, r - 1));
    auto got = Solve(a, l, a[r]);
    for (int i = got.size() - 1; i > 0; i--)
        got[i] = static_cast<ll>(got[i - 1]) * ways % mod;
    got[0] = 0;
    return got;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << getSum(Solve(a, 1, n)) << "\n";
    }
    return 0;
}
