#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct item;

using pitem = shared_ptr<item>;

struct item {
    int prior, value, cnt;
    int flag;
    pitem l, r;
    item(int value): prior{uniform_int_distribution(0, 1000000000)(rng)},
        value{value}, cnt{1}, flag{0}, l{nullptr}, r{nullptr} {}
};

int cnt(pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

pitem downOn(pitem t, int delt) {
    if (!t) return nullptr;
    auto nt = make_shared<item>(*t);
    nt->value += delt;
    nt->flag += delt;
    return nt;
}

pitem Down(pitem t) {
    if (!t || t->flag == 0) return t;
    auto nt = make_shared<item>(*t);
    if (nt->l) nt->l = downOn(nt->l, nt->flag);
    if (nt->r) nt->r = downOn(nt->r, nt->flag);
    nt->flag = 0;
    return nt;
}

pitem Merge(pitem l, pitem r) {
    if (!l) return r;
    if (!r) return l;
    l = Down(l);
    r = Down(r);
    if (l->prior > r->prior) {
        auto newl = make_shared<item>(*l);
        newl->r = Merge(newl->r, r);
        upd_cnt(newl);
        return newl;
    }
    auto newr = make_shared<item>(*r);
    newr->l = Merge(l, newr->l);
    upd_cnt(newr);
    return newr;
}

void split(pitem t, pitem& l, pitem& r, int key) {
    if (!t)
        return void(l = r = nullptr);
    t = Down(t);
    if (key <= t->value) {
        auto nt = make_shared<item>(*t);
        split(t->l, l, nt->l, key);
        r = nt;
        upd_cnt(r);
    } else {
        auto nt = make_shared<item>(*t);
        split(t->r, nt->r, r, key);
        l = nt;
        upd_cnt(l);
    }
}

int getBad(pitem t, int key) {
    if (!t) return 0;
    pitem nt = Down(t);
    if (key <= nt->value)
        return getBad(nt->l, key);
    return 1 + cnt(nt->l) + getBad(nt->r, key);
}

bool Check(int x, int k, const vector<int>& a,
    const vector<pitem>& ltreap, const vector<pitem>& rtreap) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] >= x && getBad(ltreap[i], x) + getBad(rtreap[i], x) <= k)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<pitem> ltreap(n, nullptr), rtreap(n, nullptr);
        pitem treap;
        for (int i = 0; i < n; i++) {
            pitem lef, rig;
            split(treap, lef, rig, a[i]);
            lef = downOn(lef, 1);
            ltreap[i] = Merge(lef, make_shared<item>(a[i]));
            ltreap[i] = Merge(ltreap[i], rig);
            treap = ltreap[i];
        }
        treap = nullptr;
        for (int i = n - 1; i >= 0; i--) {
            pitem lef, rig;
            split(treap, lef, rig, a[i]);
            lef = downOn(lef, 1);
            rtreap[i] = Merge(lef, make_shared<item>(a[i]));
            rtreap[i] = Merge(rtreap[i], rig);
            treap = rtreap[i];
        }
        int lef = 1, rig = 1000000000;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Check(mid, k, a, ltreap, rtreap))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}
