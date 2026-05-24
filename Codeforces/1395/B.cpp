#include <bits/stdc++.h>
using namespace std;

void Print(int r, int c) {
    cout << r << " " << c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    Print(r, c);
    for (int i = 1; i <= m; i++)
        if (i != c)
            Print(r, i);
    int lst = m;
    for (int i = 1; i <= n; i++)
        if (i != r) {
            if (lst == m) {
                for (int j = m; j >= 1; j--)
                    Print(i, j);
                lst = 1;
            } else {
                for (int j = 1; j <= m; j++)
                    Print(i, j);
                lst = m;
            }
        }
    return 0;
}
