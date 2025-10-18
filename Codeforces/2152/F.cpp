#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, z;
        cin >> n >> z;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> nxt(n);
        for (int i = 0; i < n; i++)
            nxt[i] = distance(a.begin(), ranges::upper_bound(a, a[i] + z));
        int p = sqrt(n) + 2;
        vector mem(p, vector(p, vector(p, array<short, 3>())));
        for (int i = p - 1; i >= 0; i--) {
            int pref = i * p;
            for (int j = p - 1; j >= 0; j--)
                for (int k = p - 1; k > j; k--)
                    if (pref + k < n) {
                        int to = max(pref + k + 1, nxt[pref + j]);
                        if (to < n && to < pref + p) {
                            mem[i][j][k] = mem[i][k][to - pref];
                            mem[i][j][k][2]++;
                        } else mem[i][j][k] = {static_cast<short>(j), static_cast<short>(k), 0};
                    }
        }
        int q;
        cin >> q;
        while (q--) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            if (r - l + 1 <= 2) {
                cout << r - l + 1 << "\n";
                continue;
            }
            int res = 2;
            int a = l, b = l + 1;
            while (true) {
                int i = a / p;
                int pref = i * p;
                int j = a - pref;
                int k = b - pref;
                if (k < p && mem[i][j][k][2] > 0 && pref + mem[i][j][k][1] <= r) {
                    res += mem[i][j][k][2];
                    a = pref + mem[i][j][k][0];
                    b = pref + mem[i][j][k][1];
                }
                int oth = max(b + 1, nxt[a]);
                if (oth <= r) {
                    res++;
                    a = b;
                    b = oth;
                } else break;
            }
            cout << res << "\n";
        }
    }
    return 0;
}