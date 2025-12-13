#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    ll res = 0;
    for (int i = 1; i <= n; i++)
        if (p[i]) {
            int num = i;
            int cnt = 0;
            while (p[num]) {
                int nw = p[num];
                p[num] = false;
                cnt++;
                num = nw;
            }
            res += static_cast<ll>(cnt) * (cnt - 1) / 2;
        }
    cout << res << "\n";
    return 0;
}
