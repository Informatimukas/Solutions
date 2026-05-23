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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        bool inv = false;
        vector<int> res;
        for (int i = n; i > 0; i--) {
            if (inv)
                a[i] = -a[i];
            if (a[i] > 0) {
                inv ^= true;
                res.push_back(i);
            }
        }
        cout << res.size() << "\n";
        if (res.empty()) {
            cout << "\n";
            continue;
        }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
