#include <bits/stdc++.h>
using namespace std;

constexpr int Maxb = 32;

int Solve(multiset<int> S, int c) {
    int res = 0;
    for (int i = 29; i >= 0; i--)
        if (c & 1 << i) {
            auto it = prev(S.end());
            int a = *it;
            S.erase(it);
            if ((a >> 1) >= (1 << i))
                return res;
            if (a & 1 << i) {
                S.insert((a - (1 << i)));
                continue;
            }
            res += (1 << i) - a;
            S.insert(0);
        }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> seq(n);
        for (auto& x : seq)
            cin >> x;
        ranges::sort(seq, greater());
        multiset<int> S;
        for (int i = 0; i < seq.size() && i < Maxb; i++)
            S.insert(seq[i]);
        while (q--) {
            int c;
            cin >> c;
            cout << Solve(S, c) << "\n";
        }
    }
    return 0;
}
