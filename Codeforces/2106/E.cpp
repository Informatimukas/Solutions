#include <bits/stdc++.h>
using namespace std;

int Solve(int x, int l, int r, const vector<int>& p, const vector<int>& inp) {
    if (inp[x] < l || inp[x] > r)
        return -1;
    int big = 0, small = 0;
    int goodBig = 0, goodSmall = 0;
    while (l <= r) {
        int m = (l + r) / 2;
        if (inp[x] == m) break;
        if (inp[x] < m) {
            if (p[m] < x) big++;
            else goodBig++;
            r = m - 1;
        } else {
            if (p[m] > x) small++;
            else goodSmall++;
            l = m + 1;
        }
    }
    int nd = max(big, small);
    if (x - nd - goodSmall >= 1 && x + nd + goodBig <= p.size() - 1)
        return 2 * nd;
    return -1;
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
        vector<int> inp(n + 1), p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            inp[p[i]] = i;
        }
        while (q--) {
            int l, r, k;
            cin >> l >> r >> k;
            cout << Solve(k, l, r, p, inp) << (q? ' ': '\n');
        }
    }
    return 0;
}
