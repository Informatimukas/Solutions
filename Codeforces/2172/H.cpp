#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void processDelta(int n, int delt, vector<int>& seq, vector<int>& rnk) {
    vector<int> nrnk(n), nseq(n);
    vector<int> cnt(n);
    for (auto& el : seq)
        ++cnt[rnk[el]];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int sav = sum;
        sum += cnt[i];
        cnt[i] = sav;
    }
    for (auto& el : seq) {
        int pel = (el - delt + n) % n;
        nseq[cnt[rnk[pel]]++] = pel;
    }
    ii lst = {-1, -1};
    int id = -1;
    for (auto& pel : nseq) {
        int el = (pel + delt) % n;
        ii cur = {rnk[pel], rnk[el]};
        if (cur != lst) {
            lst = cur;
            ++id;
        }
        nrnk[pel] = id;
    }
    seq = std::move(nseq);
    rnk = std::move(nrnk);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int k, t;
    cin >> k >> t;
    int n = 1 << k;
    string s;
    cin >> s;
    int z = t % k;
    vector<int> seq(n);
    vector<int> rnk(n);
    for (int i = 0; i < n; i++) {
        seq[i] = i;
        rnk[i] = s[i] - 'a';
    }
    ranges::sort(seq, [&](int a, int b) { return rnk[a] < rnk[b]; });
    int lst = -1, id = -1;
    for (auto& ind : seq) {
        if (rnk[ind] != lst) {
            ++id;
            lst = rnk[ind];
        }
        rnk[ind] = id;
    }
    for (int i = 0; i < z; i++)
        processDelta(n, 1 << (k - z + i), seq, rnk);
    for (int i = 0; i < k - z; i++)
        processDelta(n, 1 << i, seq, rnk);
    int ind = distance(rnk.begin(), ranges::min_element(rnk));
    ranges::rotate(s, s.begin() + ind);
    string nw = s;
    while (z--) {
        int pnt = 0;
        for (int i = 0; i < n / 2; i++) {
            nw[pnt++] = s[i];
            nw[pnt++] = s[n / 2 + i];
        }
        s = nw;
    }
    cout << s << "\n";
    return 0;
}
