#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int r1, r2;
    cin >> r1 >> r2;
    int c1, c2;
    cin >> c1 >> c2;
    int d1, d2;
    cin >> d1 >> d2;
    for (int a = 1; a <= 9; a++)
        for (int b = 1; b <= 9; b++) if (a != b)
            for (int c = 1; c <= 9; c++) if (c != a && c != b)
                for (int d = 1; d <= 9; d++) if (d != a && d != b && d != c)
                    if (a + b == r1 && c + d == r2 &&
                        a + c == c1 && b + d == c2 &&
                        a + d == d1 && b + c == d2) {
                        cout << a << " " << b << "\n";
                        cout << c << " " << d << "\n";
                        return 0;
                    }
    cout << "-1\n";
    return 0;
}
