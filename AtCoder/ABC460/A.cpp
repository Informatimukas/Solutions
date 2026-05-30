#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int res = 0;
    while (m) {
        int x = n % m;
        res++;
        m = x;
    }
    cout << res << "\n";
    return 0;
}
