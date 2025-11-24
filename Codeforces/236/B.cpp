#include <bits/stdc++.h>
using namespace std;

constexpr int Maxm = 1000005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector cnt(Maxm, 0);
    for (int i = 1; i < Maxm; i++)
        for (int j = i; j < Maxm; j += i)
            cnt[j]++;
    unsigned int res = 0;
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            for (int k = 1; k <= c; k++)
                res += cnt[i * j * k];
    cout << res % (1 << 30) << "\n";
    return 0;
}
