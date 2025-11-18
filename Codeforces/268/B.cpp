#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += i * (n + 1 - i) - (i - 1);
    cout << res << "\n";
    return 0;
}
