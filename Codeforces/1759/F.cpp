#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

bool Check(int x, int p, const vector<int>& a) {
    set<int> S;
    vector<ii> seq;
    for (int i = 0; i + 1 < a.size(); i++)
        S.insert(a[i]);
    if (a.back() + x < p)
        seq.emplace_back(a.back(), a.back() + x + 1);
    else {
        seq.emplace_back(a.back(), p);
        seq.emplace_back(0, a.back() + x - p + 1);
        int car = 1;
        for (int i = static_cast<int>(a.size()) - 2; i >= 0; i--) {
            car += a[i];
            S.insert(car % p);
            car /= p;
        }
        if (car)
            S.insert(car);
    }
    int need = 0;
    while (need < p)
        if (S.contains(need))
            ++need;
        else {
            bool found = false;
            for (auto& [lef, rig] : seq)
                if (lef <= need && need < rig) {
                    found = true;
                    need = rig;
                }
            if (!found)
                return false;
        }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int lef = 0, rig = p - 1;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Check(mid, p, a))
                rig = mid - 1;
            else lef = mid + 1;
        }
        cout << lef << "\n";
    }
    return 0;
}
