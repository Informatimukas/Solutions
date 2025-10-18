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
        vector<int> a(n + 1);
        vector spec(n + 1, 0), sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int b = 0;
            while (1 << b + 1 <= a[i])
                b++;
            int cnt = 0;
            for (int j = 0; j <= b; j++)
                if (a[i] & 1 << j)
                    cnt++;
            bool isSpec = cnt == 2 && static_cast<bool>(a[i] & 1);
            sum[i] = sum[i - 1] + b + (!isSpec && cnt >= 2);
            spec[i] = spec[i - 1] + isSpec;
        }
        while (q--) {
            int l, r;
            cin >> l >> r;
            int s = sum[r] - sum[l - 1];
            int t = spec[r] - spec[l - 1];
            cout << s + t / 2 << "\n";
        }
    }
    return 0;
}
