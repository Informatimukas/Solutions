#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    x %= 4;
    if (x == 0)
        cout << "1 A\n";
    else if (x == 1)
        cout << "0 A\n";
    else if (x == 2)
        cout << "1 B\n";
    else cout << "2 A\n";
    return 0;
}
