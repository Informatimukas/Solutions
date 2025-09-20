#include <bits/stdc++.h>
using namespace std;

constexpr int Maxb = 31;

int getBest(vector<int> a, int Maxb) {
    int res = 0;
    for (int b = Maxb - 1; b >= 0; b--) {
        bool found = false;
        for (auto& x : a)
            if (x & 1 << b) {
                found = true;
                break;
            }
        if (found) continue;
        int mx = -1, wth = 0;
        for (int i = 0; i < a.size(); i++) {
            int cand = a[i] & ((1 << b) - 1);
            if (cand > mx) {
                mx = cand;
                wth = i;
            }
        }
        res += (1 << b) - mx;
        a[wth] ^= mx;
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
        vector<int> a(n);
        vector has(Maxb, set<int>());
        int mask = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mask |= a[i];
            for (int j = 0; j < Maxb; j++)
                if (a[i] & 1 << j)
                    has[j].insert(i);
        }
        int curBits = __builtin_popcount(mask);
        vector<int> seq;
        for (int i = 0; i < Maxb; i++)
            if (!(mask & 1 << i))
                seq.push_back(getBest(a, i + 1));
        while (q--) {
            int b;
            cin >> b;
            int ind = distance(seq.begin(), ranges::upper_bound(seq, b));
            cout << curBits + ind << "\n";
        }
    }
    return 0;
}
