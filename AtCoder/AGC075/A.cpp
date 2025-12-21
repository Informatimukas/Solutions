#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n % 2 == 0)
        for (int v = 0; v <= 1; v++)
            for (int i = 0; i < n / 2; i++)
                cout << string(n, '0' + v) << "\n";
    else {
        for (int i = n - 1; i > 0; i -= 2)
            for (int j = 0; j < 2; j++)
                cout << string(i, '1') << string(n - i, '0') << "\n";
        cout << string(n, '0') << "\n";
    }
   /* vector C(10, vector(10, 0));
    for (int i = 0; i < C.size(); i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 0; i < 1 << (Maxd * Maxd); i++) {
        array<int, 2> cnt{};
        for (int a = 0; a < Maxd * Maxd; a++)
            for (int b = a + 1; b < Maxd * Maxd; b++)
                if (((i & 1 << a) > 0) == ((i & 1 << b) > 0)) {
                    int r1 = a / Maxd, c1 = a % Maxd;
                    int r2 = b / Maxd, c2 = b % Maxd;
                    int value = ((i & 1 << a) > 0) ? 1 : 0;
                    if (r1 <= r2 && c1 <= c2)
                        cnt[value] += C[r2 - r1 + c2 - c1][r2 - r1];
                }
        if (cnt[0] == cnt[1]) {
            cout << cnt[0] << endl;
            for (int r = 0; r < Maxd; r++) {
                for (int c = 0; c < Maxd; c++) {
                    int ind = r * Maxd + c;
                    int value = ((i & 1 << ind) > 0) ? 1 : 0;
                    cout << value;
                }
                cout << endl;
            }
        }
    }*/
    return 0;
}
