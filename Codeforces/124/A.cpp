#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    b = min(b, n - 1 - a);
    cout << b + 1 << "\n";
    return 0;
}
