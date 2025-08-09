#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;
    auto has = vector(2, vector(2, 0));
    has[0][0] = 1;
    ll res = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += s[i] == '1';
        res += has[i % 2][cur % 2];
        res += has[1 - i % 2][1 - cur % 2];
        has[i % 2][cur % 2]++;
    }
    cout << res << "\n";
    return 0;
}
