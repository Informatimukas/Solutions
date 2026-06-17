#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> inp(n + 1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        inp[a] = i;
    }
    int q;
    cin >> q;
    ll res1 = 0, res2 = 0;
    while (q--) {
        int x;
        cin >> x;
        res1 += inp[x];
        res2 += n + 1 - inp[x];
    }
    cout << res1 << " " << res2 << "\n";
    return 0;
}
