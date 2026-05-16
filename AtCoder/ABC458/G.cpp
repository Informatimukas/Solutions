#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i] >> b[i] >> c[i];
        int k = 0, best = Inf;
        for (int i = n - 1; i >= 0; i--) {
            int tk = min(a[i] / b[i], k);
            best = min(best, c[i]);
            int nk = tk;
            if (nk < k) {
                k = nk;
                best = Inf;
                continue;
            }
            a[i] -= b[i] * tk;
            if (a[i] < b[i]) {
                k = nk;
                best = Inf;
                continue;
            }
            if (a[i] < b[i] + best) {
                k = nk;
                best = b[i] + best - a[i];
                continue;
            }
            nk++;
            a[i] -= (b[i] + best);
            tk = a[i] / (b[i] + c[i]);
            nk += tk;
            a[i] -= tk * (b[i] + c[i]);
            if (a[i] < b[i]) {
                k = nk;
                best = Inf;
                continue;
            }
            k = nk;
            best = b[i] + c[i] - a[i];
        }
        cout << k << "\n";
    }
    return 0;
}
