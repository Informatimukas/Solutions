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
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++) {
            int cand = 0;
            for (int k = 0; k < n; k++)
                cand += i <= k && k <= j ? a[k] == 0 : a[k] == 1;
            res = max(res, cand);
        }
    cout << res << "\n";
    return 0;
}
