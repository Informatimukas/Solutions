#include <bits/stdc++.h>
using namespace std;

int F(int x) {
    int res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector a(n + 1, 0);
    a[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            a[i] += F(a[j]);
    cout << a[n] << "\n";
    return 0;
}
