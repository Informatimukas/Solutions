#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll k;
    cin >> k;
    k--;
    ll cur = 9, digs = 1;
    ll fir = 1;
    while (cur * digs <= k) {
        k -= cur * digs;
        cur *= 10;
        digs++;
        fir *= 10;
    }
    ll pass = k / digs;
    fir += pass;
    k %= digs;
    cout << to_string(fir)[k] << "\n";
    return 0;
}
