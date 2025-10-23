#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool Solve(const vector<ll>& seq) {
    map<ll, int> M;
    for (auto& x : seq)
        M[x]++;
    vector<ll> tmp;
    for (auto& [key, value] : M) {
        if (value != 2 || key % 2)
            return false;
        tmp.push_back(key / 2);
    }
    ll sub = 0;
    for (int i = tmp.size() - 1; i >= 0; i--) {
        ll val = tmp[i] - sub;
        if (val % (i + 1))
            return false;
        val /= (i + 1);
        if (val <= 0)
            return false;
        sub += val;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(2 * n);
        for (auto& x : a)
            cin >> x;
        cout << (Solve(a) ? "YES" : "NO") << "\n";
    }
    return 0;
}