#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1), t(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> t[i];
    int lst = 0, p = 1;
    for (int i = 0; i < m; i++) {
        int tim;
        cin >> tim;
        while (tim > lst + c[p] * t[p]) {
            lst += c[p] * t[p];
            p++;
        }
        cout << p << "\n";
    }
    return 0;
}
