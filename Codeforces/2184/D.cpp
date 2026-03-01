#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 50;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector C(Maxn, vector(Maxn, 0));
    for (int i = 0; i < Maxn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int num = n;
        int b = 0;
        while (num % 2 == 0) {
            num /= 2;
            ++b;
        }
        int cnt = 0;
        if (b + 1 <= k)
            ++cnt;
        for (int i = 0; i < b; i++)
            for (int j = 0; j <= i && i + 1 + j <= k; j++)
                cnt += C[i][j];
        cout << n - cnt << "\n";
    }
    return 0;
}
