#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    x = (x - 1 + y) % 12 + 1;
    cout << x << "\n";
    return 0;
}
