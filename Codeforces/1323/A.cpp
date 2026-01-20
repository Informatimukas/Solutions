#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        vector<int> res;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int a;
            cin >> a;
            if (a % 2 == 0)
                res = {i};
        }
        if (res.empty() && n >= 2)
            res = {1, 2};
        if (res.empty())
            cout << "-1\n";
        else {
            cout << res.size() << "\n";
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
        }
    }
    return 0;
}
