#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct pos {
    int w;
    vector<ii> seq;
    vector<ull> cnt;
    vector<ull> sum;
    ull getValue(ull hm) {
        int ind = distance(cnt.begin(), ranges::upper_bound(cnt, hm));
        return sum[ind - 1] + (hm - cnt[ind - 1]) * seq[ind].first;
    }
};

ull solveSimple(array<pos, 3>& a, ull c, ull lft1, ull lft0) {
    ull tk1 = min(c / 2, lft1);
    ull best = a[1].getValue(lft1) - a[1].getValue(lft1 - tk1);
    ull tk0 = min(c, lft0);
    best = max(best, a[0].getValue(lft0) - a[0].getValue(lft0 - tk0));
    return best;
}

ull Solve2(ull lef, ull rig, ull myvalue, array<pos, 3>& a, ull c, ull lft1, ull lft2) {
    if (rig - lef <= 4) {
        ull res = 0;
        for (ull i = lef; i <= rig; i++)
            res = max(res, i * myvalue + solveSimple(a, c - 3 * i, lft1, lft2));
        return res;
    }
    ull m1 = (2 * lef + rig) / 3, m2 = (lef + 2 * rig) / 3;
    ull q1 = m1 * myvalue + solveSimple(a, c - 3 * m1, lft1, lft2);
    ull q2 = m2 * myvalue + solveSimple(a, c - 3 * m2, lft1, lft2);
    if (q1 >= q2)
        return Solve2(lef, m2, myvalue, a, c, lft1, lft2);
    return Solve2(m1, rig, myvalue, a, c, lft1, lft2);
}

ull Solve10(ull lef, ull rig, ull myvalue, array<pos, 3>& a, ull c, ull lft1, ull lft2) {
    if (rig - lef <= 4) {
        ull res = 0;
        for (ull i = lef; i <= rig; i++)
            res = max(res, i * myvalue + solveSimple(a, c - 3 * i, lft1 - i, lft2 - i));
        return res;
    }
    ull m1 = (2 * lef + rig) / 3, m2 = (lef + 2 * rig) / 3;
    ull q1 = m1 * myvalue + solveSimple(a, c - 3 * m1, lft1 - m1, lft2 - m1);
    ull q2 = m2 * myvalue + solveSimple(a, c - 3 * m2, lft1 - m2, lft2 - m2);
    if (q1 >= q2)
        return Solve10(lef, m2, myvalue, a, c, lft1, lft2);
    return Solve10(m1, rig, myvalue, a, c, lft1, lft2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    ll c;
    cin >> n >> c;
    array<vector<ii>, 3> seq{};
    for (int i = 0; i < n; i++) {
        int w, v, k;
        cin >> w >> v >> k;
        seq[w - 1].emplace_back(v, k);
    }
    array<pos, 3> a{};
    for (int i = 0; i < seq.size(); i++) {
        ranges::sort(seq[i]);
        a[i].w = i + 1;
        a[i].seq.resize(seq[i].size() + 1);
        a[i].cnt.resize(seq[i].size() + 1);
        a[i].sum.resize(seq[i].size() + 1);
        for (int j = 0; j < seq[i].size(); j++) {
            a[i].seq[j + 1] = seq[i][j];
            a[i].cnt[j + 1] = a[i].cnt[j] + seq[i][j].second;
            a[i].sum[j + 1] = a[i].sum[j] + static_cast<ull>(seq[i][j].first) * seq[i][j].second;
        }
    }
    ull res = 0, got = 0;
    int i = seq[2].size(), j = seq[1].size(), k = seq[0].size();
    while (i > 0 || (j > 0 && k > 0))
        if ((j == 0 || k == 0) || a[2].seq[i].first >= a[1].seq[j].first + a[0].seq[k].first) {
            ull lef = 0, rig = min(c / 3, static_cast<ll>(a[2].seq[i].second));
            res = max(res, got + Solve2(lef, rig, a[2].seq[i].first, a, c, a[1].cnt[j], a[0].cnt[k]));
            c -= 3 * a[2].seq[i].second;
            got += static_cast<ll>(a[2].seq[i].first) * a[2].seq[i].second;
            if (c < 0) break;
            --i;
        } else {
            ll mn = min(a[1].seq[j].second, a[0].seq[k].second);
            ull lef = 0, rig = min(c / 3, mn);
            res = max(res, got + Solve10(lef, rig, a[1].seq[j].first + a[0].seq[k].first, a, c, a[1].cnt[j], a[0].cnt[k]));
            c -= 3 * mn;
            got += static_cast<ll>(a[1].seq[j].first + a[0].seq[k].first) * mn;
            if (c < 0)
                break;
            a[1].seq[j].second -= mn;
            a[1].cnt[j] -= mn;
            a[1].sum[j] -= static_cast<ull>(mn) * a[1].seq[j].first;
            if (a[1].seq[j].second == 0)
                --j;
            a[0].seq[k].second -= mn;
            a[0].cnt[k] -= mn;
            a[0].sum[k] -= static_cast<ull>(mn) * a[0].seq[k].first;
            if (a[0].seq[k].second == 0)
                --k;
        }
    if (c >= 0)
        res = max(res, got + solveSimple(a, c, a[1].cnt[j], a[0].cnt[k]));
    cout << res << "\n";
    return 0;
}
