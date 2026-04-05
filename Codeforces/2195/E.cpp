#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;

void Solve(int v, const vector<int>&L, const vector<int>& R, vector<ll>& P) {
    if (L[v]) {
        Solve(L[v], L, R, P);
        P[v] = (P[v] + 1 + P[L[v]]) % mod;
    }
    if (R[v]) {
        Solve(R[v], L, R, P);
        P[v] = (P[v] + 1 + P[R[v]]) % mod;
    }
    P[v] = (P[v] + 1) % mod;
}

void Propagate(int v, const vector<int>& L, const vector<int>& R, vector<ll>& P) {
    if (L[v]) {
        P[L[v]] = (P[L[v]] + P[v]) % mod;
        Propagate(L[v], L, R, P);
    }
    if (R[v]) {
        P[R[v]] = (P[R[v]] + P[v]) % mod;
        Propagate(R[v], L, R, P);
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
        vector<int> L(n + 1), R(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> L[i] >> R[i];
        vector P(n + 1, 0ll);
        Solve(1, L, R, P);
        Propagate(1, L, R, P);
        for (int i = 1; i <= n; i++)
            cout << P[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
