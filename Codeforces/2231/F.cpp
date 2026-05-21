#include <bits/stdc++.h>
using namespace std;

constexpr int Inf = 1000000000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector isSquare(n + 1, false);
        for (int i = 0; i * i <= n; i++)
            isSquare[i * i] = true;
        vector min2(n + 1, Inf);
        for (int i = 0; i <= n; i++) {
            if (isSquare[i]) {
                min2[i] = 0;
                continue;
            }
            for (int j = 1; i + j * j <= n; j++)
                if (isSquare[i + j * j]) {
                    min2[i] = j * j;
                    break;
                }
            for (int j = 1; i - j * j >= 0; j--)
                if (isSquare[i - j * j]) {
                    min2[i] = 0;
                    break;
                }
        }
        while (q--) {
            int a, b;
            cin >> a >> b;
            if (isSquare[b - a]) {
                cout << "1\n";
                continue;
            }
            if (min2[b - a] <= max(n - b, a - 1)) {
                cout << "2\n";
                continue;
            }
            bool ok = false;
            for (int i = 1; a - i * i >= 1; i++) {
                int nw = a - i * i;
                if (min2[b - nw] <= max(n - b, nw - 1)) {
                    ok = true;
                    break;
                }
            }
            for (int i = 1; a + i * i <= n; i++) {
                int nw1 = a + i * i;
                int nw2 = b;
                if (nw1 > nw2)
                    swap(nw1, nw2);
                if (min2[nw2 - nw1] <= max(n - nw2, nw1 - 1)) {
                    ok = true;
                    break;
                }
            }
            if (ok) {
                cout << "3\n";
                continue;
            }
            cout << "4\n";
        }
    }
    return 0;
}
