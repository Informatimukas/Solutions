#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int Maxn = 400005;
const int Maxd = 3;
const int Inf = 1000000000;

struct BIT {
    int arr[Maxn], n;
    int tot;
    void Init(int gn) {
        n = gn;
        fill(arr, arr + n + 1, 0);
        tot = 0;
    }
    void Add(int x) {
        tot++;
        for (int i = x + 1; i > 0; i -= i & -i)
            arr[i]++;
    }
    int Get(int x) {
        int res = 0;
        for (int i = x + 1; i <= n; i += i & -i)
            res += BIT[i];
        return res;
    }
};

struct side {
    BIT bit[Maxd];
    iii my[Maxn];
    int n, pnt;
    void Init(int gn) {
        n = gn;
        for (int i = 0; i < Maxd; i++)
            bit[i].Init(n);
        pnt = 0;
    }
    void Push(const iii &a) {
        my[pnt++] = a;
    }
    void finishPushing() {
        sort(my, my + pnt);
        pnt = 0;
    }
    bool hasNext() { return pnt < n; }
    void addNext() {
        int ind;
        switch (my[pnt].second) {
            case -1: ind = 0;
                     break;
            case 1: ind = 1;
                    break;
            case 0: ind = 0;
                    break;
        }
        bit[ind].Add(my[pnt++].first.second);
    }
    iii& getNext() { return my[pnt]; }
    int Get(const iii &p) {
        if (p.first.first >= Inf)
            return 0;
        int res = 0;
        if (p.second <= 0)
            res += bit[0].tot + bit[1].Get(p.first.second);
        else res += bit[0].Get(p.first.second) + bit[1].tot
                    + bit[2].tot - bit[2].Get(p.first.second);
        return res;
    }
};

struct solver {
    int un[Maxn];
    side s[2];
    int ulen, n;
    void Init() {
        ulen = 0;
    }
    void Push(int v) {
        un[ulen++] = v;
    }
    void finishPushing() {
        n = ulen;
        ulen = unique(un, un + ulen) - un;
        s[0].Init(n);
        s[1].Init(n);
    }
    int getId(int v) {
        return lower_bound(un, un + ulen, v) - un
    }
    void addSides(const iii &a, const iii &b) {
        s[0].Push(a);
        s[1].Push(b);
    }
    // Sort by p.first.second;
    ll Solve() {
        ll res = 0;
        s[0].finishPushing();
        s[1].finishPushing();
        while (s[0].hasNext() || s[1].hasNext())
            if (s[0].hasNext() && (!s[1].hasNext() || s[0].getNext() < s[1].getNext())) {
                res += s[1].Get(s[0].getNext());
                s[0].addNext();
            } else {
                res += s[0].Get(s[1].getNext());
                s[1].addNext();
            }
        return res;
    }
};

int main()
{
    return 0;
}
