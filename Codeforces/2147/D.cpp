#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        map<int, int> M;
        ll res1 = 0, res2 = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            res1 += a / 2;
            res2 += a / 2;
            if (a % 2)
                M[a]++;
        }
        vector<int> seq;
        for (auto& p : M)
            seq.push_back(p.second);
        ranges::sort(seq, greater());
        for (int i = 0; i < seq.size(); i++)
            if (i % 2) res2 += seq[i];
            else res1 += seq[i];
        cout << res1 << " " << res2 << "\n";
    }
    return 0;
}
