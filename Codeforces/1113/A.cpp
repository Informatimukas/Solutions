#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v;
    cin >> n >> v;
    v = min(n - 1, v);
    int res = v;
    for (int i = 2; i <= n - v; i++)
        res += i;
    cout << res << "\n";
    return 0;
}
