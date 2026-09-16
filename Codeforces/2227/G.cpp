#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Get(const vector<int>& BIT, int ind) {
    int res = 0;
    for (int i = ind; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

void Add(vector<int>& BIT, int ind) {
    for (int i = ind + 1; i < BIT.size(); i += i & -i)
        BIT[i]++;
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
        vector<ll> sum(n + 1);
        vector<ll> un;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            sum[i] = a[i] - sum[i - 1];
            un.push_back(-sum[i]);
        }
        un.push_back(0);
        ranges::sort(un);
        array<vector<int>, 2> BIT;
        for (int i = 0; i < 2; i++)
            BIT[i].resize(un.size() + 1);
        ll res = 0;
        int ind = distance(un.begin(), ranges::lower_bound(un, 0));
        Add(BIT[0], ind);
        for (int i = 1; i <= n; i++) {
            ind = distance(un.begin(), ranges::lower_bound(un, sum[i]));
            res += Get(BIT[(i - 1) % 2], ind);
            ind = distance(un.begin(), ranges::lower_bound(un, -sum[i]));
            Add(BIT[i % 2], ind);
        }
        cout << res << "\n";
    }
    return 0;
}
