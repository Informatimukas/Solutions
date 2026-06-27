#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        if (m == 1) {
            cout << "0\n";
            continue;
        }
        map<int, vector<int>> M;
        for (int i = 0; i < n; i++)
            M[i - a[i]].push_back(i);
        vector<int> L(n);
        vector<int> R(n);
        vector<int> memL(n);
        vector<int> memR(n);
        memL[0] = L[0] = a[0] == 1;
        int mx = L[0];
        for (int i = 1; i < n; i++) {
            memL[i] = L[i] = mx + (a[i] == 1);
            mx = max(mx, L[i]);
            if (a[i] > 1) {
                int ind = i - (a[i] - 1);
                if (ind >= 0) {
                    L[ind]++;
                    mx = max(mx, L[ind]);
                }
            }
        }
        memR[n - 1] = R[n - 1] = a[n - 1] == m;
        mx = R[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            memR[i] = R[i] = mx + (a[i] == m);
            mx = max(mx, R[i]);
            if (a[i] < m) {
                int ind = i + (m - a[i]);
                if (ind < n) {
                    R[ind]++;
                    mx = max(mx, R[ind]);
                }
            }
        }
        int res = 0;
        for (int i = 0; i + m <= n; i++) {
            int nd = i - 1;
            auto lef = ranges::lower_bound(M[nd], i + 1);
            auto rig = ranges::lower_bound(M[nd], i + m - 1);
            res = max(res, memL[i] + memR[i + m - 1] + static_cast<int>(distance(lef, rig)));
        }
        vector bestL(n + 1, -1000000000);
        for (int i = 0; i + m <= n; i++) {
            int nd = i - 1;
            auto lef = ranges::lower_bound(M[nd], i + 1);
            auto rig = ranges::lower_bound(M[nd], i + m);
            bestL[i + m] = max(bestL[i + m - 1], memL[i] + static_cast<int>(distance(lef, rig)) - (i + m));
        }
        for (int i = 0; i + m <= n; i++) {
            int nd = i - 1;
            auto lef = ranges::lower_bound(M[nd], i);
            auto rig = ranges::lower_bound(M[nd], i + m - 1);
            int bestR = memR[i + m - 1] + static_cast<int>(distance(lef, rig));
            res = max(res, bestR + i + bestL[i]);
        }
        cout << n - res << "\n";
    }
    return 0;
}
