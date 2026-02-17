#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, h;
        cin >> n >> m >> h;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        map<int, int> M;
        while (m--) {
            int b, c;
            cin >> b >> c;
            M[b] += c;
            if (a[b] + M[b] > h)
                M.clear();
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] + M[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
