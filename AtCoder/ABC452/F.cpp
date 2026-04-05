#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Add(vector<int>& BIT, int x, int delt) {
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] += delt;
}

int Get(const vector<int>& BIT, int x) {
    int res = 0;
    for (int i = x; i < BIT.size(); i += i & -i)
        res += BIT[i];
    return res;
}

ll Solve(const vector<int>& a, ll k) {
    if (k < 0)
        return 0;
    vector BIT(a.size() + 1, 0);
    int l = 0;
    ll cur = 0;
    ll res = 0;
    for (int i = 0; i < a.size(); i++) {
        cur += Get(BIT, a[i]);
        Add(BIT, a[i], 1);
        while (cur > k) {
            int delt = i - l + 1 - Get(BIT, a[l]);
            cur -= delt;
            Add(BIT, a[l++], -1);
        }
        res += i - l + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll k;
    cin >> n >> k;
    vector<int> P(n);
    for (auto& x : P)
        cin >> x;
    cout << Solve(P, k) - Solve(P, k - 1) << "\n";
    return 0;
}
