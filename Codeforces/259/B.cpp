#include <bits/stdc++.h>
using namespace std;

constexpr int Maxd = 3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<array<int, Maxd>, Maxd> B{};
    array<int, Maxd> sum{};
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++) {
            cin >> B[i][j];
            sum[i] += B[i][j];
        }
    int mx = *ranges::max_element(sum);
    for (int i = 0; i < Maxd; i++)
        B[i][i] = mx + 1 - sum[i];
    int mysum = B[0][0] + B[1][1] + B[2][2];
    int d = (mx + 1 - mysum) / 2;
    for (int i = 0; i < Maxd; i++)
        B[i][i] += d;
    for (int i = 0; i < Maxd; i++)
        for (int j = 0; j < Maxd; j++)
            cout << B[i][j] << (j + 1 < Maxd ? ' ' : '\n');
    return 0;
}
