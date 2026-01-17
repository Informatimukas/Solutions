#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    int res = 0;
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1]) {
            int best = 1;
            while (i - best - 1 >= 0 && i + best < n && a[i - best - 1] == a[i - 1] &&
                a[i + best] == a[i])
                best++;
            res = max(res, 2 * best);
        }
    cout << res << "\n";
    return 0;
}
