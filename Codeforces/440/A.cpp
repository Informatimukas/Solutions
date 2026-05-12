#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int res = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        res ^= a ^ i;
    }
    cout << res << "\n";
    return 0;
}
