#include <bits/stdc++.h>
using namespace std;

constexpr int Maxk = 20;

int getPrev(int pnt, int fin) {
    if (fin == pnt)
        return pnt + 2;
    if (fin == pnt + 1)
        return pnt;
    if (fin == pnt + 2)
        return pnt + 1;
    return -1;
}

int Move(int pos, int steps, const vector<vector<int>>& nxt) {
    for (int i = Maxk - 1; i >= 0; i--)
        if (1 << i <= steps) {
            pos = nxt[pos][i];
            steps -= 1 << i;
        }
    return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> seq(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> seq[i];
        vector a(n + 1, false);
        a[1] = a[2] = true;
        int has = 2;
        int pnt = 1;
        for (int i = 3; i < n; i++)
            if (has >= 2)
                if (seq[i - 2] == i - 2 || seq[i - 1] == i - 2 || seq[i] == i - 2) {
                    pnt = i - 2;
                    has = 0;
                } else {
                    a[i] = true;
                    has++;
                }
            else if (seq[i] == getPrev(pnt, seq[i - 2]))
                has = 0;
            else {
                a[i] = true;
                has++;
            }
        vector nxt(n + 1, vector<int>(Maxk));
        for (int i = 1; i <= n; i++)
            nxt[i][0] = a[i] ? i + 1 : i - 2;
        for (int j = 1; j < Maxk; j++)
            for (int i = 1; i <= n; i++)
                nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        bool ok = true;
        for (int i = 1; i <= n; i++)
            if (Move(i, n, nxt) != seq[i]) {
                ok = false;
                break;
            }
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
