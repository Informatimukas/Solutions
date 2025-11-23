#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        int cnt4 = 0, cnt8 = 0;
        for (auto& ch : s)
            if (ch == '4')
                cnt4++;
            else cnt8++;
        x = abs(x);
        y = abs(y);
        x -= min(x, cnt8);
        y -= min(y, cnt8);
        if (x + y <= cnt4)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
