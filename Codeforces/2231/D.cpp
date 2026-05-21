#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000ll;

bool Check(const string& s, const vector<ll>& a, const vector<ll>& c, const vector<ll>& res) {
    ll mx = -Inf, cur = 0;
    for (int i = 0; i < a.size(); i++) {
        if (s[i] == '1' && a[i] != res[i])
            return false;
        cur += res[i];
        mx = max(mx, cur);
        if (mx != c[i])
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> a(n);
        for (auto& x : a)
            cin >> x;
        vector<ll> c(n);
        for (auto& x : c)
            cin >> x;
        vector<ll> res(n);
        res[0] = c[0];
        int nxt = 1;
        ll best = c[0];
        for (int i = 1; i < c.size(); i++) {
            res[i] = s[i] == '0' ? -Inf : a[i];
            if (best < c[i]) {
                ll sum = c[i] - best;
                best = c[i];
                vector<int> seq;
                for (int j = nxt; j <= i; j++)
                    if (s[j] == '0')
                        seq.push_back(j);
                    else sum -= a[j];
                if (!seq.empty()) {
                    sum += Inf * static_cast<ll>(seq.size() - 1);
                    res[seq.back()] = sum;
                }
                nxt = i + 1;
            }
        }
        if (Check(s, a, c, res)) {
            cout << "Yes\n";
            for (int i = 0; i < res.size(); i++)
                cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
        } else cout << "No\n";
    }
    return 0;
}
