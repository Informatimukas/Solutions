#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 4;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> B(Maxd);
    for (auto& x : B)
        cin >> x;
    for (int i = 0; i + 2 <= Maxd; i++)
        for (int j = 0; j + 2 <= Maxd; j++) {
            int got = (B[i][j] == '#') + (B[i + 1][j] == '#') + (B[i][j + 1] == '#') + (B[i + 1][j + 1] == '#');
            if (got != 2) {
                cout << "YES\n";
                return 0;
            }
        }
    cout << "NO\n";
    return 0;
}
