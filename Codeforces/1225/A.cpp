#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << 10 * a << " " << 10 * a + 1 << "\n";
    else if (a + 1 == b)
        cout << a << " " << b << "\n";
    else if (a == 9 && b == 1)
        cout << "9 10\n";
    else cout << "-1\n";
    return 0;
}
