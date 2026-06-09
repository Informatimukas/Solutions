#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int res = n / 2 + n % 2;
    while (res % m)
        res++;
    cout << (res > n ? -1 : res) << "\n";
    return 0;
}
