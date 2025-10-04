#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    map<int, int> M;
    for (int i = 1; i <= n; i++)
        M.emplace(i, 1);
    while (q--) {
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        while (!M.empty() && M.begin()->first <= x) {
            cnt += M.begin()->second;
            M.erase(M.begin());
        }
        cout << cnt << "\n";
        M[y] += cnt;
    }
    return 0;
}
