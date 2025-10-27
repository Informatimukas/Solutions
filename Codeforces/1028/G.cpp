#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxq = 5;
constexpr int Maxk = 10000;
constexpr ll M = 10004205361450474ll;

ll Solve(int q, ll fir, vector<vector<ll>>& mx, const vector<ll>& withBigK) {
    if (fir >= Maxk)
        return fir + withBigK[q];
    if (mx[q][fir])
        return mx[q][fir];
    auto& res = mx[q][fir];
    if (q == 0)
        return res = fir;
    res = fir;
    for (int i = 0; i < fir; i++) {
        res = Solve(q - 1, res, mx, withBigK);
        if (res > M) break;
        ++res;
    }
    if (res <= M)
        res = Solve(q - 1, res, mx, withBigK);
    return res;
}

int Ask(const vector<ll>& seq) {
    if (seq.empty())
        return 0;
    cout << seq.size();
    for (auto& x : seq)
        cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void findNumber(int q, ll fir, vector<vector<ll>>& mx, const vector<ll>& withBigK) {
    vector<ll> seq;
    ll cur = fir;
    for (int i = 0; i < min(fir, static_cast<ll>(Maxk)); i++) {
        cur = Solve(q - 1, cur, mx, withBigK);
        if (cur > M)
            break;
        seq.push_back(cur);
        ++cur;
    }
    int got = Ask(seq);
    if (got < 0)
        return;
    if (got > 0)
        fir = seq[got - 1] + 1;
    findNumber(q - 1, fir, mx, withBigK);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<ll> withBigK(Maxq + 1, 0);
    withBigK[0] = 0;
    for (int i = 1; i < withBigK.size(); i++)
        withBigK[i] = withBigK[i - 1] * (Maxk + 1) + Maxk;
    vector mx(Maxq + 1, vector(Maxk, 0ll));
    Solve(Maxq, 1, mx, withBigK);
    findNumber(Maxq, 1, mx, withBigK);
    return 0;
}
