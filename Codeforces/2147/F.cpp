#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Inf = 1000000000;

ll getSum(int l, int r, int mx) {
    if (l > r) return 0;
    l = mx - l + 1;
    r = mx - r + 1;
    return static_cast<ll>(l + r) * (l - r + 1) / 2;
}

struct Block {
    vector<int> cnt;
    int l, r;
    int filled;
    int incoming, outgoing, fre;
    ll ans0;
    Block(int l, int r): cnt(r - l + 1, 0), l(l), r(r), filled(0),
        incoming(r + 1), outgoing(l), fre(0), ans0(r - l + 1) {}
    ll getCurrent() const {
        return filled > 0 ? getSum(l, r, incoming) :
            getSum(r - fre + 1, r, incoming) + ans0;
    }
    int getOutgoing() const {
        return filled > 0 ? Inf : outgoing;
    }
    ll Update(int L, int R, int delt, int newIncoming) {
        cout << "Update " << L << " " << R << " " << delt << " " << newIncoming << endl;
        ll old = -getCurrent();
        incoming = newIncoming;
        if (L <= l && r <= R) {
            filled += delt;
            return old + getCurrent();
        }
        if (r < L || R < l)
            return old + getCurrent();
        outgoing = Inf;
        fre = 0;
        ans0 = 0;
        for (int i = r; i >= l; --i) {
            if (L <= i && i <= R)
                cnt[i - l] += delt;
            if (cnt[i - l] == 0)
                outgoing = i;
            if (outgoing < Inf)
                ans0 += outgoing - i + 1;
            else fre++;
        }
        cout << "old = " << old << " " << getCurrent() << " " << ans0 << endl;
        return old + getCurrent();
    }
};

ll UpdateBlocks(vector<Block>& blocks, int a, int b, int delt) {
    ll res = 0;
    int cur = Inf;
    for (auto& x : blocks | views::reverse) {
        res += x.Update(a, b, delt, cur);
        cur = min(cur, x.getOutgoing());
    }
    cout << "res = " << res << endl;
    return res;
}

ll Swap(vector<int>& seq, int ind1, int ind2, vector<Block>& blocks) {
    if (ind1 > 1 && seq[ind1 - 1] > seq[ind1])
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> P(n + 1);
        vector<int> inP(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> inP[i];
            P[inP[i]] = i;
        }
        vector<Block> blocks;
        int part = sqrt(n) + 2;
        int cur = 1;
        while (cur <= n) {
            int to = min(cur + part - 1, n);
            blocks.emplace_back(cur, cur + part - 1);
            cur = to + 1;
        }
        vector<int> seq(n + 1), inseq(n + 1), target(n + 1);
        iota(seq.begin(), seq.end(), 0);
        iota(inseq.begin(), inseq.end(), 0);
        for (int i = 1; i <= n; i++)
            cin >> target[i];
        ll res = static_cast<ll>(n) * (n - 1) / 2 + n;
        cout << "res = " << res << endl;
        for (int i = 1; i <= n; i++) {
            int need = target[P[i]];
            int wh = inseq[need];
            if (wh != i) {
                int a = seq[i], b = seq[wh];
                if (i > wh)
                    swap(a, b);
                res += UpdateBlocks(blocks, a, b);
                swap(seq[i], seq[wh]);
                swap(inseq[seq[i]], inseq[seq[wh]]);
            }
        }
        while (q--) {
            int tp, i, j;
            cin >> tp >> i >> j;
            int ind1 = inP[i], ind2 = inP[j];
            if (ind1 > ind2)
                swap(ind1, ind2);
            res += UpdateBlocks(blocks, seq[ind1], seq[ind2]);
            swap(seq[ind1], seq[ind2]);
            if (tp == 1)
                swap(inP[i], inP[j]);
            cout << res << "\n";
        }
    }
    return 0;
}