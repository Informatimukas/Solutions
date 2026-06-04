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
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        int res = 0;
        for (int i = n - 1; i >= 0; i--)
            if (a[i] > 0) {
                res++;
                if (i)
                    a[i - 1] += a[i];
            }
        cout << res << "\n";
    }
    return 0;
}
