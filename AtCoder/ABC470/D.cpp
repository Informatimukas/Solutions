#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> P(n + 1), Q(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i];
        Q[P[i]] = i;
    }
    while (q--) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int x, y;
            cin >> x >> y;
            swap(P[x], P[y]);
            swap(Q[P[x]], Q[P[y]]);
        } else swap(P, Q);
    }
    for (int i = 1; i <= n; i++)
        cout << P[i] << (i + 1 <= n ? ' ' : '\n');
    return 0;
}
