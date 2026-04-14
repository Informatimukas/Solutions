#include <bits/stdc++.h>
using namespace std;

void Solve(int x, int y) {
    int n = x + y;
    if (n % 2 == 0) {
        if (--x < 0) {
            cout << "NO\n";
            return;
        }
    } else if (--y < 0) {
        cout << "NO\n";
        return;
    }
    if (x > y) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int cur = 2;
    while (x > 0) {
        cout << "1 " << cur << "\n";
        cout << cur << " " << cur + 1 << "\n";
        cur += 2;
        x--; y--;
    }
    while (y > 0) {
        cout << "1 " << cur << "\n";
        cur++;
        y--;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int x, y;
        cin >> x >> y;
        Solve(x, y);
    }
    return 0;
}
