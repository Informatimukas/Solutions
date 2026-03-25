#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = n / 3 * 2;
    if (n % 3)
        ++res;
    cout << res << "\n";
    return 0;
}
