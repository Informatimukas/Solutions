#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b, c;
    cin >> a >> b >> c;
    int res = ((a - b) * c + b - 1) / b;
    cout << res << "\n";
    return 0;
}
