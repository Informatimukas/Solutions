#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool Solve(const vector<int>& a, ll m, int x) {
    ll cur = 0;
    ll cheap = 0;
    map<int, ll> M;
    for (auto num : a)
        if (num < x) {
            cheap += num - 1;
            cur--;
        } else {
            ++M[num];
            cur++;
        }
    while (!M.empty() && M.rbegin()->first >= 2 * x && m > 0) {
        ll tk = min(m, M.rbegin()->second);
        cur += tk;
        m -= tk;
        M[M.rbegin()->first / 2] += tk;
        M[(M.rbegin()->first + 1) / 2] += tk;
        M.rbegin()->second -= tk;
        if (M.rbegin()->second == 0)
            M.erase(prev(M.end()));
    }
    ll tk = min(m, cheap);
    m -= tk;
    cur -= tk;
    cheap -= tk;
    if (m == 0)
        return cur > 0;
    while (!M.empty())
        if (M.rbegin()->first == 2 * x - 1) {
            ll canTake = x - 1;
            ll pay = x;
            tk = min(m / canTake, M.rbegin()->second);
            m -= tk * canTake;
            cur -= tk * pay;
            M.rbegin()->second -= tk;
            if (M.rbegin()->second == 0) {
                M.erase(prev(M.end()));
                M[x] += tk;
            } else {
                if (m > 0) {
                    m--;
                    cur -= 2;
                    cur -= m;
                    m = 0;
                }
                break;
            }
        } else {
            ll canTake = M.rbegin()->first - 1;
            ll pay = M.rbegin()->first + 1;
            tk = min(m / canTake, M.rbegin()->second);
            m -= tk * canTake;
            cur -= tk * pay;
            M.rbegin()->second -= tk;
            if (M.rbegin()->second == 0)
                M.erase(prev(M.end()));
            else {
                if (m > 0) {
                    m--;
                    cur -= 3;
                    cur -= m;
                    m = 0;
                }
                break;
            }
        }
    return cur > 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        ll m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        int lef = 2, rig = 1000000007;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Solve(a, m, mid))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}