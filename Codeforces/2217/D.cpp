#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector special(n, false);
        int b;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            special[x - 1] = true;
            b = a[x - 1];
        }
        int lst = b;
        for (int i = 0; i < n; i++)
            if (a[i] != lst) {
                lst = a[i];
                a[i] = 1;
            } else a[i] = 0;
        a.push_back(lst != b);
        int sum = 0, mx = 0, cur = 0;
        for (int i = 0; i <= n; i++) {
            sum += a[i];
            cur += a[i];
            if (special[i]) {
                mx = max(mx, cur);
                cur = 0;
            }
        }
        mx = max(mx, cur);
        int rem = sum - mx;
        if (rem >= mx)
            cout << sum / 2 << "\n";
        else cout << mx << "\n";
    }
    return 0;
}
