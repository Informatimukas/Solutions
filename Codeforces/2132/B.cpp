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
        ll n;
        cin >> n;
        ll pw = 1;
        vector<ll> res;
        while (pw <= n / 10) {
            pw *= 10;
            if (n % (pw + 1) == 0)
                res.push_back(n / (pw + 1));
        }
        ranges::reverse(res);
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}
