#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector a(n + 1, 0);
        vector B(n + 1, array<int, 2>());
        vector dif(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            B[i] = B[i - 1];
            B[i][a[i]]++;
            dif[i] = dif[i - 1] + (a[i] != a[i - 1]);
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            array<int, 2> freq{};
            for (int i = 0; i < freq.size(); i++)
                freq[i] = B[r][i] - B[l - 1][i];
            if (freq[0] % 3 || freq[1] % 3) {
                cout << "-1\n";
                continue;
            }
            int res = (freq[0] + freq[1]) / 3;
            if (dif[r] - dif[l] == r - l)
                res++;
            cout << res << "\n";
        }
    }
    return 0;
}
