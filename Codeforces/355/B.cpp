#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int n, m;
    cin >> n >> m;
    int res = 0;
    for (auto z : {n, m}) {
        int cur = 0;
        for (int i = 0; i < z; i++) {
            int a;
            cin >> a;
            cur += min(a * c1, c2);
        }
        res += min(cur, c3);
    }
    res = min(res, c4);
    cout << res << "\n";
    return 0;
}
