#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        res += a;
    }
    int ans = 0;
    for (int i = 1; i <= 5; i++)
        if ((res + i) % (n + 1) != 1)
            ans++;
    cout << ans << "\n";
    return 0;
}
