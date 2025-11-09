#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, X;
        cin >> n >> X;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        ranges::sort(a);
        int l = 0, r = n - 1;
        ll sum = 0;
        ll bonus = 0;
        vector<int> res;
        while (l <= r)
            if ((sum + a[r]) / X > sum / X) {
                sum += a[r];
                bonus += a[r];
                res.push_back(a[r--]);
            } else {
                sum += a[l];
                res.push_back(a[l++]);
            }
        cout << bonus << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}