#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, s, x;
    cin >> t >> s >> x;
    if (x == t || x > t + 1 && (x - t) % s <= 1)
        cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
