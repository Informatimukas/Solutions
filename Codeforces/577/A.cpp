#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int res = 0;
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0) {
            int j = x / i;
            if (i <= n && j <= n)
                res += 1 + (i != j);
        }
    cout << res << "\n";
    return 0;
}
