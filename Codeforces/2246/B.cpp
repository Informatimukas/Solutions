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
        if (n == 2) {
            cout << "-1\n";
            continue;
        }
        vector<ll> res = {1, 2, 3};
        ll sum = 6;
        while (res.size() < n) {
            res.push_back(sum);
            sum *= 2;
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
