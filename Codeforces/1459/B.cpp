#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a = n / 2, b = n - a;
    int res = (a + 1) * (b + 1);
    if (a != b)
        res *= 2;
    cout << res << "\n";
    return 0;
}
