#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 300005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector divs(Maxn, vector<int>());
    for (int i = 2; i < Maxn; i++)
        for (int j = i; j < Maxn; j += i)
            divs[j].push_back(i);
    vector has(Maxn, false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> seq(n);
        for (auto& x : seq) {
            cin >> x;
            has[x] = true;
        }
        vector got(n + 1, Maxn);
        if (has[1])
            got[1] = 1;
        for (int i = 2; i <= n; i++)
            for (auto d : divs[i])
                if (has[d]) {
                    if (i == d)
                        got[i] = min(got[i], 1);
                    else got[i] = min(got[i], got[i / d] + 1);
                }
        for (int i = 1; i <= n; i++) {
            if (got[i] >= Maxn)
                got[i] = -1;
            cout << got[i] << (i + 1 <= n ? ' ' : '\n');
        }
        for (auto& x : seq)
            has[x] = false;
    }
    return 0;
}
