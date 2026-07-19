#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int g = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        g = gcd(g, x);
    }
    cout << g * n << "\n";
    return 0;
}
