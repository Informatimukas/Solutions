#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> seq(n);
    for (auto& x : seq)
        cin >> x;
    ranges::sort(seq);
    int cnt = n / 2;
    ll res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
        if (i < cnt)
            res1 += seq[i];
        else res2 += seq[i];
    cout << res1 * res1 + res2 * res2 << "\n";
    return 0;
}
