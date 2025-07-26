#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 300005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int mod1, mod2;
int arg1, arg2;
int pw1[Maxn], pw2[Maxn];
int T;
int n, m;
int N;
int A[Maxn];
int B[Maxn];
ii HA[Maxn], HB[Maxn];

typedef struct item * pitem;
struct item {
    int prior;
    ii value;
    int cnt;
    pitem l, r;
    item(const ii &value = ii(0, 0)) {
        prior = uniform_int_distribution(1, 1000000000)(rng);
        this->value = value;
        cnt = 1;
        l = r = nullptr;
    }
};

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void output (pitem t) {
    if (!t)  return;
    output (t->l);
    printf("%d %d\n", t->value.first, t->value.second);
    output (t->r);
    delete t;
}

bool Prime(int x)
{
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0) return false;
    return true;
}

ii addHash(ii h, int nw)
{
    h.first = (ll(h.first) * arg1 + nw) % mod1;
    h.second = (ll(h.second) * arg2 + nw) % mod2;
    return h;
}

ii getHash(ii H[], int l, int r)
{
    ii res = H[r];
    if (--l >= 0) {
        res.first = (ll(res.first) - ll(pw1[r - l]) * H[l].first % mod1 + mod1) % mod1;
        res.second = (ll(res.second) - ll(pw2[r - l]) * H[l].second % mod2 + mod2) % mod2;
    }
    return res;
}

void Progress(int &row, int &col, int hm = 1) {
    while (hm--)
        if (col == 0) {
            row++;
            col = m - 1;
        } else col--;
}

int main()
{
    mod1 = uniform_int_distribution<int>(10000000, 1000000000)(rng);
    mod2 = uniform_int_distribution<int>(10000000, 1000000000)(rng);
    arg1 = uniform_int_distribution<int>(100000, 10000000)(rng);
    arg2 = uniform_int_distribution<int>(100000, 10000000)(rng);
    while (!Prime(mod1)) mod1++;
    while (!Prime(mod2)) mod2++;
    while (!Prime(arg1)) arg1++;
    while (!Prime(arg2)) arg2++;
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < Maxn; i++) {
        pw1[i] = ll(pw1[i - 1]) * arg1 % mod1;
        pw2[i] = ll(pw2[i - 1]) * arg2 % mod2;
    }
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        N = n * m;
        ii h = {0, 0};
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            h = addHash(h, A[i]);
            HA[i] = h;
        }
        int res = 0;
        deque <int> D;
        pitem treap = nullptr;
        int row = 1, col = 0;
        for (int i = 0; i < n; i++) {
            h = {0, 0};
            for (int j = 0; j < m; j++) {
                scanf("%d", &B[j]);
                h = addHash(h, B[j]);
                HB[j] = h;
            }
            int add = 0;
            for (int j = 0; j < m; j++)
                if (!D.empty())
                    if (D.front() == B[j]) {
                        add++;
                        D.pop_front();
                        Progress(row, col);
                    } else {
                        pitem lef, rig;
                        split(treap, lef, rig, col);
                        auto me = new item({row, B[j]});
                        merge(treap, lef, me);
                        merge(treap, treap, rig);
                        add++;
                        res++;
                    }
                else {
                    int cand = m - j;
                    if (getHash(HA, i * m, i * m + cand - 1) ==
                        getHash(HB, m - cand, m - 1)) {
                        Progress(row, col, cand);
                        break;
                    }
                    pitem lef, rig;
                    split(treap, lef, rig, col);
                    auto me = new item({row, B[j]});
                    merge(treap, lef, me);
                    merge(treap, treap, rig);
                    add++;
                    res++;
                }
            for (int j = (i + 1) * m - add; j < (i + 1) * m; j++)
                D.push_back(A[j]);
        }
        printf("%d\n", res);
        output(treap);
    }
    return 0;
}