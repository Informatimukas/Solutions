#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> Check(const vector<ll>& f) {
    vector<ll> ans(f.size());
    ans[0] = 0;
    ll s = -f[1] + f[0];
    for (int i = 1; i + 1 < f.size(); i++) {
        ll tp = s + f[i + 1] - f[i];
        if (tp % 2)
            return {};
        ans[i] = tp / 2;
    }
    ans[f.size() - 1] = s;
    ll sum = 0;
    for (int i = 0; i + 1 < f.size(); i++)
        sum += ans[i];
    ll x = (f.back() - sum) / static_cast<ll>(f.size() - 1);
    for (int i = 0; i + 1 < f.size(); i++)
        ans[i] += x;
    ans.back() += 2 * x;
    for (int i = f.size() - 1; i > 0; i--)
        ans[i] -= ans[i - 1];
    return ans;
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
        vector<ll> f(n);
        for (auto& x : f)
            cin >> x;
        auto res = Check(f);
        for (int j = 0; j < res.size(); j++)
            cout << res[j] << (j + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
