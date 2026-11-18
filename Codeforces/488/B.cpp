#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    for (int i = 4; i / 4 * 3 <= lim; i += 4) {
        vector<int> res, rem;
        int L = i / 4, R = i / 4 * 3;
        set S = {L, R};
        for (auto x : a)
            if (S.contains(x))
                S.erase(x);
            else rem.push_back(x);
        if (rem.size() > 2)
            continue;
        for (auto x : S)
            res.push_back(x);
        bool fal = false;
        if (rem.empty()) {
            res.push_back(i / 2);
            res.push_back(i / 2);
        } else if (rem.size() == 1) {
            int lft = i - rem[0];
            if (L <= rem[0] && rem[0] <= R && L <= lft && lft <= R)
                res.push_back(lft);
            else fal = true;
        } else if (rem.size() == 2) {
            if (rem[0] + rem[1] == i && L <= rem[0] && rem[0] <= R && L <= rem[1] && rem[1] <= R) {}
            else fal = true;
        } else fal = true;
        if (fal) continue;
        cout << "YES\n";
        for (auto x : res)
            cout << x << "\n";
        return 0;
    }
    cout << "NO\n";
    return 0;
}
