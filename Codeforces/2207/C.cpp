#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector mx(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            mx[i][i] = a[i];
            for (int j = i + 1; j < n; j++)
                mx[i][j] = max(mx[i][j - 1], a[j]);
        }
        vector tolef(n, vector<ll>(n));
        vector torig(n, vector<ll>(n));
        for (int i = 0; i < n; i++) {
            tolef[i][i] = torig[i][i] = h - a[i];
            for (int j = i - 1; j >= 0; j--)
                torig[j][i] = torig[j + 1][i] + h - mx[j][i];
            for (int j = i + 1; j < n; j++)
                tolef[i][j] = tolef[i][j - 1] + h - mx[i][j];
        }
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int pnt = i + 1;
            for (int j = i; j < n; j++) {
                while (pnt < j && mx[i][pnt] <= mx[pnt][j])
                    pnt++;
                ll cand = torig[0][i];
                if (pnt - 1 > i)
                    cand += tolef[i][pnt - 1] - (h - a[i]);
                if (pnt < j)
                    cand += torig[pnt][j] - (h - a[j]);
                cand += tolef[j][n - 1];
                if (i == j)
                    cand -= (h - a[i]);
                res = max(res, cand);
            }
        }
        cout << res << "\n";
    }
    return 0;
}
