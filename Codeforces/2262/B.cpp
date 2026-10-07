#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

void Add(vector<ll>& BIT, int x, ll val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] += val;
}

ll Get(const vector<ll>& BIT, int x) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res += BIT[i];
    return res;
}

int main() {
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
        vector<int> p(n + 1);
        vector<int> inp(n + 1);
        vector<int> mx(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            inp[p[i]] = i;
        }
        for (int i = 1; i <= n; i++)
            mx[i] = max(mx[i - 1], inp[i]);
        vector<vector<int>> quer(n + 1);
        vector<int> lef(n + 1);
        vector<int> rig(n + 1);
        for (int i = 1; i <= n; i++) {
            lef[i] = 0;
            rig[i] = inp[i] - 1;
            if (lef[i] <= rig[i]) {
                int mid = (lef[i] + rig[i]) / 2;
                quer[mid].push_back(i);
            }
        }
        for (int z = 0; z < 20; z++) {
            vector<ll> BIT(n + 1);
            vector<vector<int>> nquer(n + 1);
            for (int i = 1; i <= n; i++)
                Add(BIT, i, a[i]);
            for (int i = 0; i < n; i++) {
                for (auto x : quer[i]) {
                    if (Get(BIT, x - 1) < a[x])
                        rig[x] = i - 1;
                    else lef[x] = i + 1;
                    if (lef[x] <= rig[x]) {
                        int mid = (lef[x] + rig[x]) / 2;
                        nquer[mid].push_back(x);
                    }
                }
                Add(BIT, p[i + 1], -a[p[i + 1]]);
            }
            quer = nquer;
        }
        vector<int> delt(n + 1);
        for (int i = 1; i <= n; i++) {
            cout << "i = " << i << ", lef = " << lef[i] << ", rig = " << mx[i - 1] << ", " << inp[i] << endl;
            delt[lef[i]]++;
            delt[min(mx[i - 1], inp[i])]--;
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += delt[i];
            cout << cur << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
