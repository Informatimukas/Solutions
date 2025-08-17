#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct item {
    int prior, value, index, cnt;
    int best;
    shared_ptr<item> l, r;
    item(int val, int ind) {
        prior = uniform_int_distribution(0, 1000000000)(rng);
        value = best = val;
        index = ind;
        cnt = 1;
    }
};

int max(shared_ptr<item> it) { return it ? it->best : 0; }

int cnt (shared_ptr<item> it) {
    return it ? it->cnt : 0;
}

void upd_cnt (shared_ptr<item> it) {
    if (it) {
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
        it->best = max({max(it->l), max(it->r), it->value});
    }
}

void merge (shared_ptr<item>& t, shared_ptr<item> l, shared_ptr<item> r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (shared_ptr<item> t, shared_ptr<item> & l, shared_ptr<item> & r, int a, int c) {
    if (!t)
        return void( l = r = nullptr );
    int bestVal = max(t->value, max(t->r));
    int count = cnt(t->r) + 1;
    if (a > bestVal && c >= count)
        split(t->l, l, t->l, a, c - count), r = t;
    else split(t->r, t->r, r, a, c), l = t;
    upd_cnt (t);
}

void output (shared_ptr<item> t, vector<int>& res) {
    if (!t)  return;
    output (t->l, res);
    res.push_back(t->index);
    output (t->r, res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    shared_ptr<item> treap;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, c;
        cin >> a >> c;
        shared_ptr<item> l, r;
        split(treap, l, r, a, c);
        merge(treap, l, make_shared<item>(a, i));
        merge(treap, treap, r);
    }
    vector<int> res;
    output(treap, res);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    return 0;
}