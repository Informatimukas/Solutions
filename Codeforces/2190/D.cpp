#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

struct UnionSet {
    vector<int> par, siz;
    UnionSet(int n): par(n + 1), siz(n + 1, 1) {
        iota(par.begin(), par.end(), 0);
    }
    int getPar(int x) { return par[x] == x ? x : par[x] = getPar(par[x]); } 
}

ll toPower(ll a, ll p) {
    ll res = 1;
    while (p) {
        if (p & 1ll)
            res = res * a % mod;
        p >>= 1ll;
        a = a * a % mod;
    }
    return res;
}

ll Inv(ll x) { return toPower(x, mod - 2); } 
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        
    }
    return 0;
}
