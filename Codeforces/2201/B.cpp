#include <bits/stdc++.h>
using namespace std;

int getRight(int n) {
    return 2 * n - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k < n || k > getRight(n)) {
            cout << "NO\n";
            continue;
        }
        vector<int> res;
        while (n)
            if (k > n && k == getRight(n)) {
                res.push_back(1);
                res.push_back(2);
                for (int i = 3; i <= n; i++) {
                    res.push_back(i);
                    res.push_back(i - 2);
                }
                res.push_back(n - 1);
                res.push_back(n);
                n = 0;
            } else {
                res.push_back(n);
                res.push_back(n);
                --n;
                --k;
            }
        cout << "YES\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
