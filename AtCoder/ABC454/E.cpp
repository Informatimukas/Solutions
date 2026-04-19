#include <bits/stdc++.h>
using namespace std;

void Solve(int r1, int c1, int x, int y, int r2, int c2, string& res) {
    if (r1 + 1 == r2 && c1 + 1 == c2) {
        if (r1 == x)
            res += "DR";
        else res += "RD";
        return;
    }
    if (r1 + 2 <= x) {
        res += string(c2 - c1, 'R') + "D" + string(c2 - c1, 'L') + "D";
        Solve(r1 + 2, c1, x, y, r2, c2, res);
        return;
    }
    if (c1 + 2 <= y) {
        res += string(r2 - r1, 'D') + "R" + string(r2 - r1, 'U') + "R";
        Solve(r1, c1 + 2, x, y, r2, c2, res);
        return;
    }
    if (r2 - 2 >= x) {
        Solve(r1, c1, x, y, r2 - 2, c2, res);
        res += "D" + string(c2 - c1, 'L') + "D" + string(c2 - c1, 'R');
        return;
    }
    Solve(r1, c1, x, y, r2, c2 - 2, res);
    res += "R" + string(r2 - r1, 'U') + "R" + string(r2 - r1, 'D');
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n % 2 || (a + b) % 2 == 0) {
            cout << "No\n";
            continue;
        }
        string res;
        Solve(1, 1, a, b, n, n, res);
        cout << "Yes\n";
        cout << res << "\n";
    }
    return 0;
}
