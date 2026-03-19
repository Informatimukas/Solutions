#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        string zers(a.length(), '0');
        string ones(a.length(), '1');
        if (a != b && (a == zers || a == ones || b == zers || b == ones))
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
