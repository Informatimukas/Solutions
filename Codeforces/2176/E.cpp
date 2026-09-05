#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

ii Better(const ii& a, const ii& b) {
    if (a.first != b.first)
        return a.first > b.first ? a : b;
    return a.second < b.second ? a : b;
}

void Spread(int ind, const vector<int>& a, vector<int>& c, set<int>& S, int val, ll& sum, ii& best) {
    auto it = S.lower_bound(ind);
    vector<int> rem;
    while (it != S.end() && a[ind] >= a[*it]) {
        rem.push_back(*it);
        S.erase(it++);
    }
    while (it != S.begin()) {
        --it;
        if (a[ind] < a[*it])
            break;
        rem.push_back(*it);
        S.erase(it++);
    }
    for (auto r : rem) {
        if (val == 0) {
            sum -= c[r];
            c[r] = 0;
        } else {
            c[r] = val;
            sum += c[r];
        }
        best = Better(best, {a[r], c[r]});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> c(n);
        vector<ii> srt(n);
        for (int i = 0; i < n; i++) {
            cin >> c[i];
            srt[i] = {c[i], i};
        }
        ranges::sort(srt);
        set<int> S, Z;
        for (int i = 0; i < n; i++) {
            S.insert(i);
            Z.insert(i);
        }
        ll sum = 0;
        ii best = {0, 0};
        for (auto ind : srt | views::values)
            Spread(ind, a, c, S, c[ind], sum, best);
        cout << sum - best.second;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            p--;
            Spread(p, a, c, Z, 0, sum, best);
            cout << " " << sum - best.second;
        }
        cout << "\n";
    }
    return 0;
}
