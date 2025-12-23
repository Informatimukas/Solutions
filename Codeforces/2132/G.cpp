#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll Inf = 1000000000000000000ll;
constexpr int Maxn = 1000005;

struct hasher {
    ll arg, mod;
    vector<ll> pw;
    bool Prime(int x) {
        if (x <= 1)
            return false;
        if (x == 2)
            return true;
        if (x % 2 == 0)
            return false;
        for (int i = 3; i * i <= x; i += 2)
            if (x % i == 0)
                return false;
        return true;
    }
    hasher(): pw(Maxn) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        arg = uniform_int_distribution(1000000, 100000000)(rng);
        mod = uniform_int_distribution(200000000, 1000000000)(rng);
        while (!Prime(arg))
            ++arg;
        while (!Prime(mod))
            ++mod;
        pw[0] = 1;
        for (int i = 1; i < pw.size(); i++)
            pw[i] = pw[i - 1] * arg % mod;
    }
};

vector<string> Rotate(const vector<string>& B) {
    int n = B.size(), m = B[0].size();
    vector<string> nw(m);
    for (int i = 0; i < m; i++) {
        nw[i].resize(n);
        for (int j = 0; j < n; j++)
            nw[i][j] = B[n - 1 - j][i];
    }
    return nw;
}

ll Solve(const vector<string>& B, const hasher& h) {
    ll res = Inf;
    vector val(B[0].size(), 0ll), rval(B[0].size(), 0ll);
    for (int i = 0; i < B.size(); i++) {
        ll cur = 0, rcur = 0;
        for (int j = 0; j < B[i].size(); j++) {
            ll let = B[i][j] - 'a' + 1;
            val[j] = (val[j] * h.arg + let) % h.mod;
            rval[j] = (rval[j] + let * h.pw[i]) % h.mod;
            cur = (cur * h.pw[i + 1] + val[j]) % h.mod;
            rcur = (rcur + rval[j] * h.pw[j * (i + 1)]) % h.mod;
            if (cur == rcur) {
                ll r = i + 1;
                ll remr = B.size() - r;
                ll c = j + 1;
                ll remc = B[i].size() - c;
                ll cand = (r + 2 * remr) * (c + 2 * remc) - (r + remr) * (c + remc);
                res = min(res, cand);
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    hasher h;
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<string> B(n);
        for (auto& x : B)
            cin >> x;
        ll res = Inf;
        for (int i = 0; i < 4; i++) {
            res = min(res, Solve(B, h));
            B = Rotate(B);
        }
        cout << res << "\n";
    }
    return 0;
}
