#include <bits/stdc++.h>
using namespace std;

string toString(int x) {
    if (x == 0)
        return "";
    return toString(x / 2) + string(1, x % 2 + '0');
}

string solveSame(int l, int r, int n) {
    auto L = toString(l), R = toString(r);
    string res(n, '0');
    int len = L.length();
    int p = 0;
    while (p < len && L[p] == R[p])
        p++;
    for (int i = 0; i < n; i++)
        res[i] = i % len < p ? L[i % len] : '0';
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int l, r, n;
        cin >> l >> r >> n;
        string L = toString(l), R = toString(r);
        if (L.length() == R.length()) {
            cout << solveSame(l, r, n) << "\n";
            continue;
        }
        if (L.length() + 1 < R.length()) {
            int my = R.length() * (R.length() - 1);
            string res(n, '0');
            for (int i = 0; i < n; i++)
                if (i % my == 0)
                    res[i] = '1';
            cout << res << "\n";
            continue;
        }
        int mid = 1 << (R.length() - 1);
        string res = min(solveSame(l, mid - 1, n), solveSame(mid, r, n));
        string cand(n, '0');
        int cur = 0;
        for (int i = 0; i < n; i += R.length()) {
            cand[i] = L[cur];
            cur = (cur + 1) % L.length();
        }
        res = min(res, cand);
        cout << res << "\n";
    }
    return 0;
}
