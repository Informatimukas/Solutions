#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void Add(vector<int>& BIT, int x) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i]++;
}

int Get(const vector<int>& BIT, int x) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector BIT(n + 1, 0);
    vector<int> inp(n + 1);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        inp[p] = i;
    }
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        Add(BIT, inp[i]);
        int left = Get(BIT, inp[i]);
        int right = i + 1 - left;
        res += static_cast<ll>(left) * right;
    }
    cout << res << "\n";
    return 0;
}
