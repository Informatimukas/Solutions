#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxd = 16;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    array<ll, Maxd> cnt0{}, sum0{};
    array<ll, Maxd> cnt1{}, sum1{};
    cnt0[0] = 1; sum0[0] = 0;
    cnt1[0] = 1; sum1[0] = 0;
    for (int i = 1; i < Maxd; i++) {
        cnt0[i] = 10 * cnt0[i - 1];
        sum0[i] = 10 * sum0[i - 1] + cnt0[i] / 2 * 9;
        cnt1[i] = 9 * cnt0[i - 1];
        sum1[i] = 9 * sum0[i - 1] + cnt1[i] * 5;
    }
    int T;
    cin >> T;
    while (T--) {
        ll k;
        cin >> k;
        ll res = 0;
        int d = 1;
        while (d * cnt1[d] <= k) {
            k -= d * cnt1[d];
            res += sum1[d];
            d++;
        }
        string s;
        int curSum = 0;
        for (int i = 1; i <= d; i++) {
            int curDig = i == 1? 1: 0;
            while (d * cnt0[d - i] <= k) {
                k -= d * cnt0[d - i];
                res += (curSum + curDig) * cnt0[d - i] + sum0[d - i];
                curDig++;
            }
            curSum += curDig;
            s += curDig + '0';
        }
        for (int i = 0; i < k; i++)
            res += s[i] - '0';
        cout << res << "\n";
    }
    return 0;
}
