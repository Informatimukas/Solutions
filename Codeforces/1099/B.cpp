#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 2000000007;
    for (int i = 1; i * i <= n; i++) {
        int j = (n + i - 1) / i;
        res = min(res, i + j);
    }
    cout << res << "\n";
    return 0;
}
