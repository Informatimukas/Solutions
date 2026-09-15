#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int res = 0;
    while (n--) {
        int a;
        cin >> a;
        res += (a + k - 1) / k;
    }
    res = (res + 1) / 2;
    cout << res << "\n";
    return 0;
}
