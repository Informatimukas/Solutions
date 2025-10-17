#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

ii Intersect(const ii& a, const ii& b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

void Print(const vector<int>& seq) {
    for (int i = 0; i < seq.size(); i++)
        cout << seq[i] << (i + 1 < seq.size() ? ' ' : '\n');
}

int Check(int n, int pos, const vector<ii>& seq) {
    ii res = {0, n - 1};
    for (auto& p : seq)
        if (p.first <= pos && pos <= p.second)
            res = Intersect(res, p);
    if (res.first == pos)
        res.first++;
    return res.first <= res.second ? res.first : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> res(n);
        iota(res.begin(), res.end(), 0);
        vector<ii> seq(m);
        for (auto& [a, b] : seq) {
            cin >> a >> b;
            a--;
            b--;
        }
        ii all = {0, n - 1};
        for (auto& p : seq)
            all = Intersect(all, p);
        if (all.first <= all.second) {
            swap(res[0], res[all.first]);
            Print(res);
            continue;
        }
        int zer = -1, one = -1;
        for (int i = 0; i < n; i++) {
            int got = Check(n, i, seq);
            if (got != -1) {
                one = got;
                zer = i;
                break;
            }
        }
        if (zer != -1) {
            swap(res[0], res[zer]);
            int old = zer == 1 ? 0 : 1;
            swap(res[old], res[one]);
            Print(res);
            continue;
        }
        swap(res[1], res[2]);
        Print(res);
    }
    return 0;
}
