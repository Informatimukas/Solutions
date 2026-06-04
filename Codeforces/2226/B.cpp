#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int res = 0;
        for (int i = 0; i + 1 < n; i++)
            if (gcd(a[i], a[i + 1]) == max(a[i], a[i + 1]) - min(a[i], a[i + 1]))
                res++;
        cout << res << "\n";
    }
    return 0;
}
