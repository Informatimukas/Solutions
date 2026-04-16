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
        int ind;
        cin >> ind;
        ind--;
        int res1 = 0, res2 = 0;
        for (int i = ind - 1; i >= 0; i--)
            if (a[i] != a[i + 1])
                res1++;
        for (int i = ind + 1; i < n; i++)
            if (a[i] != a[i - 1])
                res2++;
        int res = max(res1, res2);
        if (res % 2)
            res++;
        cout << res << "\n";
    }
    return 0;
}
