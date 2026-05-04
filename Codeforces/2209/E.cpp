#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll Solve(const string_view s) {
    vector Z(s.length(), 0);
    vector from(s.length(), -1);
    vector<int> R(s.length() + 1), L(s.length() + 1);
    iota(R.begin(), R.end(), 1);
    iota(L.begin(), L.end(), -1);
    int l = -1, r = -1;
    for (int i = 1; i < s.length(); i++) {
        if (i <= r)
            Z[i] = min(Z[i - l], r - i);
        while (i + Z[i] < s.length() && s[i + Z[i]] == s[Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }
    for (int i = s.length() - 1; i > 0; i--) {
        int cur = i;
        while (cur < i + Z[i]) {
            from[cur] = i - 1;
            R[L[cur]] = R[cur];
            L[R[cur]] = L[cur];
            cur = R[cur];
        }
    }
    ll res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (from[i] >= 0)
            from[i] = from[from[i]] + 1;
        else from[i] = 1;
        res += from[i];
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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << Solve(s.substr(l, r - l + 1)) << "\n";
        }
    }
    return 0;
}
