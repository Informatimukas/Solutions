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
        if (n <= 3) {
            cout << "-1\n";
            continue;
        }
        vector<int> res;
        int st = n % 2 ? 1 : 2;
        while (st <= n) {
            res.push_back(st);
            st += 2;
        }
        res.push_back(n - 3);
        res.push_back(n - 1);
        st = n - 5;
        while (st >= 1) {
            res.push_back(st);
            st -= 2;
        }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
