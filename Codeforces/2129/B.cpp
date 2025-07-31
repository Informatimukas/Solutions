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
        vector<int> p(n);
        for (auto& el: p)
            cin >> el;
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int ind = 0;
            for (int j = 0; j < n; j++)
                if (p[j] > i) ind++;
                else if (p[j] == i) break;
            res += min(ind, n - i - ind);
        }
        cout << res << "\n";
    }
    return 0;
}
