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
        vector<int> p(n + 1), inp(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
            inp[p[i]] = i;
        }
        string x;
        cin >> x;
        x = " " + x;
        if (x[1] == '1' || x[n] == '1' || x[inp[1]] == '1' || x[inp[n]] == '1') {
            cout << "-1\n";
            continue;
        }
        cout << "5\n";
        cout << 1 << " " << inp[1] << "\n";
        cout << 1 << " " << inp[n] << "\n";
        cout << inp[1] << " " << n << "\n";
        cout << inp[n] << " " << n << "\n";
        cout << min(inp[1], inp[n]) << " " << max(inp[1], inp[n]) << "\n";
    }
    return 0;
}
