#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    int x = 2000000007;
    for (int i = 1; i < k; i++)
        if (n % i == 0) {
            int d = n / i;
            x = min(x, d * k + i);
        }
    cout << x << "\n";
    return 0;
}
