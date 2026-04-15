#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct item {
    int prior, value, cnt;
    int flag;
    int l, r;
    item(int value): prior{uniform_int_distribution(0, 1000000000)(rng)},
        value{value}, cnt{1}, flag{0}, l{0}, r{0} {}
};

vector<item> all;

int cnt(int it) {
    return it ? all[it].cnt : 0;
}

void upd_cnt(int it) {
    if (it)
        all[it].cnt = cnt(all[it].l) + cnt(all[it].r) + 1;
}

void push(int it) {
    if (it && all[it].flag) {
        all[it].value += all[it].flag;
        if (all[it].l)
            all[all[it].l].flag += all[it].flag;
        if (all[it].r)
            all[all[it].r].flag += all[it].flag;
        all[it].flag = 0;
    }
}

void merge(int& t, int l, int r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (all[l].prior > all[r].prior)
        merge (all[l].r, all[l].r, r),  t = l;
    else
        merge (all[r].l, l, all[r].l),  t = r;
    upd_cnt (t);
}

void split(int t, int& l, int& r, int key) {
    if (!t)
        return void(l = r = 0);
    push (t);
    if (key <= all[t].value)
        split (all[t].l, l, all[t].l, key),  r = t;
    else
        split (all[t].r, all[t].r, r, key),  l = t;
    upd_cnt (t);
}

int getBad(int t, int key) {
    if (!t) return 0;
    push(t);
    if (key <= all[t].value)
        return getBad(all[t].l, key);
    return 1 + cnt(all[t].l) + getBad(all[t].r, key);
}

void processTreap(int& treap, int x, int a) {
    if (a >= x) {
        int tmp;
        split(treap, treap, tmp, x);
        if (treap)
            all[treap].flag++;
    } else {
        int lef, rig;
        split(treap, lef, rig, a);
        if (lef)
            all[lef].flag++;
        all.emplace_back(a);
        int index = all.size() - 1;
        merge(treap, lef, index);
        merge(treap, treap, rig);
    }
}

bool Check(int x, int k, const vector<int>& a) {
    vector need(a.size(), 0);
    all = {item(0)};
    int treap = 0;
    bool was = false;
    for (int i = 0; i < a.size(); i++) {
        processTreap(treap, x, a[i]);
        if (a[i] >= x) {
            need[i] += getBad(treap, x);
            if (need[i] <= k) was = true;
        }
    }
    if (!was)
        return false;
    all = {item(0)};
    treap = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        processTreap(treap, x, a[i]);
        if (a[i] >= x) {
            need[i] += getBad(treap, x);
            if (need[i] <= k)
                return true;
        }
    }
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
        int lef = 1, rig = 1000000000;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (Check(mid, k, a))
                lef = mid + 1;
            else rig = mid - 1;
        }
        cout << rig << "\n";
    }
    return 0;
}