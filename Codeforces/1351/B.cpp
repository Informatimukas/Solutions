#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        int c, d;
        cin >> a >> b;
        cin >> c >> d;
        if (a > b)
            swap(a, b);
        if (c > d)
            swap(c, d);
        if (b == d && a + c == b)
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
