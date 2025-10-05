#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll F(int r, int k, const vector<int>& a) {
    ll res = 0;
    map<int, int> M;
    for (int i = 0, j = 0; i < a.size(); i++) {
        M[a[i]]++;
        while (M.size() > k || i - j + 1 > r) {
            if (--M[a[j]] == 0)
                M.erase(a[j]);
            j++;
        }
        res += i - j + 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << F(r, k, a) - F(l - 1, k, a) - F(r, k - 1, a) + F(l - 1, k - 1, a) << "\n";
    }
    return 0;
}
