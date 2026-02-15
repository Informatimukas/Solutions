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
        int n, Ax, Ay, Bx, By;
        cin >> n >> Ax >> Ay >> Bx >> By;
        vector<int> X(n);
        for (auto& x : X)
            cin >> x;
        vector<int> Y(n);
        for (auto& y : Y)
            cin >> y;
        ll lefY = Ay, rigY = Ay;
        ll lef = Bx - Ax, rig = Bx - Ax;
        map<int, vector<int>> M;
        for (int i = 0; i < n; i++)
            M[X[i]].push_back(Y[i]);
        for (auto& seq : M | views::values) {
            ranges::sort(seq);
            ll nlef = min(lef + abs(lefY - seq.back()) + seq.back() - seq[0],
                rig + abs(rigY - seq.back()) + seq.back() - seq[0]);
            ll nrig = min(lef + abs(lefY - seq[0]) + seq.back() - seq[0],
                rig + abs(rigY - seq[0]) + seq.back() - seq[0]);
            lef = nlef;
            rig = nrig;
            lefY = seq[0];
            rigY = seq.back();
        }
        ll res = min(lef + abs(lefY - By), rig + abs(rigY - By));
        cout << res << "\n";
    }
    return 0;
}
