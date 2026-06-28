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
        map<int, int> M;
        int lim = 0;
        for (int i = n - 1; i >= 0; i--) {
            M[i - m] = max(M[i + 1 - m],  max(lim, M[i - 1]));
            M[i - a[i]]++;
            if (i + m <= n)
                lim = max(lim, M[i - 1]);
        }
        int res = n - max(lim, M[-1]);
        cout << res << "\n";
    }
    return 0;
}
