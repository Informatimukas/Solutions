#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k < n || k == 2 * n) {
            cout << "-1\n";
            continue;
        }
        vector B(n, vector<int>(n));
        int cur = 1;
        B[0][0] = cur++;
        int car = 2 * n - 1 - k;
        for (int i = 0; i < n - 1; i++)
            if (i < car)
                B[i + 1][i + 1] = cur++;
            else B[0][i + 1] = cur++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!B[i][j])
                    B[i][j] = cur++;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cout << B[i][j] << (j + 1 < n ? ' ' : '\n');
    }
    return 0;
}
