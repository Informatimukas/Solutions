#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

void Add(vector<int>& BIT, int x, int val) {
    for (int i = x + 1; i < BIT.size(); i += i & -i)
        BIT[i] = (BIT[i] + val) % mod;
}

int Get(const vector<int>& BIT, int x) {
    int res = 0;
    for (int i = x + 1; i > 0; i -= i & -i)
        res = (res + BIT[i]) % mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector seq(n + 1, vector<int>());
    vector<int> nxt(n + 1);
    for (int i = n; i > 0; i--) {
        seq[a[i]].push_back(i);
        if (seq[a[i]].size() >= a[i])
            nxt[i] = seq[a[i]][seq[a[i]].size() - a[i]];
        else nxt[i] = -1;
    }
    vector BIT(n + 5, 0);
    vector lst(n + 1, -1);
    Add(BIT, 0, 1);
    for (int i = 1; i <= n; i++) {
        if (nxt[i] != -1) {
            int ways = (Get(BIT, i - 1) - Get(BIT, lst[a[i]]) + mod) % mod;
            Add(BIT, nxt[i], ways);
        }
        lst[a[i]] = i;
    }
    int res = (Get(BIT, n) - Get(BIT, 0) + mod) % mod;
    cout << res << "\n";
    return 0;
}
