#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxd = 11;
constexpr int Maxp = 6;

void Add(auto& BIT, const array<int, Maxp>& seq, ll val) {
    for (int a = seq[0]; a < Maxd; a += a & -a)
        for (int b = seq[1]; b < Maxd; b += b & -b)
            for (int c = seq[2]; c < Maxd; c += c & -c)
                for (int d = seq[3]; d < Maxd; d += d & -d)
                    for (int e = seq[4]; e < Maxd; e += e & -e)
                        for (int f = seq[5]; f < Maxd; f += f & -f)
                            BIT[a][b][c][d][e][f] += val;
}

ll Get(const auto& BIT, const array<int, Maxp>& seq) {
    ll res = 0;
    for (int a = seq[0]; a > 0; a -= a & -a)
        for (int b = seq[1]; b > 0; b -= b & -b)
            for (int c = seq[2]; c > 0; c -= c & -c)
                for (int d = seq[3]; d > 0; d -= d & -d)
                    for (int e = seq[4]; e > 0; e -= e & -e)
                        for (int f = seq[5]; f > 0; f -= f & -f)
                            res += BIT[a][b][c][d][e][f];
    return res;
}

ll Compute(const auto& BIT, int lvl, const string& lef, const string& rig, array<int, Maxp>& seq, int delt) {
    if (lvl >= lef.size())
        return Get(BIT, seq) * delt;
    seq[lvl] = rig[lvl] - '0' + 1;
    ll res = Compute(BIT, lvl + 1, lef, rig, seq, delt);
    seq[lvl] = lef[lvl] - '0';
    res += Compute(BIT, lvl + 1, lef, rig, seq, -delt);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector BIT(Maxd, vector(Maxd, vector(Maxd, vector(Maxd, vector(Maxd, vector<ll>(Maxd))))));
    int n;
    cin >> n;
    array<int, Maxp> seq{};
    while (n--) {
        string s;
        cin >> s;
        ll v;
        cin >> v;
        for (int i = 0; i < seq.size(); i++)
            seq[i] = s[i] - '0' + 1;
        Add(BIT, seq, v);
    }
    int q;
    cin >> q;
    while (q--) {
        string lef, rig;
        cin >> lef >> rig;
        bool ok = true;
        for (int i = 0; i < lef.length(); i++)
            if (lef[i] > rig[i]) {
                ok = false;
                break;
            }
        cout << (ok ? Compute(BIT, 0, lef, rig, seq, 1) : 0) << "\n";
    }
    return 0;
}
