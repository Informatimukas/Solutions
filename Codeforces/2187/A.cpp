#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000007;

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
        auto b = a;
        ranges::sort(b);
        int res = Inf;
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
                res = min(res, max(a[i] - b[0], b[n - 1] - a[i]));
        if (res >= Inf)
            res = -1;
        cout << res << "\n";
    }
    return 0;
}
