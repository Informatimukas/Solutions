#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 1;
    for (int i = 1; i < n; i++)
        res += 4 * i;
    cout << res << "\n";
    return 0;
}
