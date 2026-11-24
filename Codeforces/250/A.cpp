#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int cur = 0;
    vector res = {0};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            if (++cur >= 3) {
                cur = 1;
                res.push_back(i);
            }
        }
    }
    res.push_back(n);
    cout << res.size() - 1 << "\n";
    for (int i = 0; i + 1 < res.size(); i++)
        cout << res[i + 1] - res[i] << (i + 2 < res.size() ? ' ' : '\n');
    return 0;
}
