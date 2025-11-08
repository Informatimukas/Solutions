// Next steps: the following code solves the problem for given l only;
// Need to think about a solution suitable for range of queries;
// The idea is to consider the inp[a] -> inp[a + 1] intervals.
#include <bits/stdc++.h>
using namespace std;

constexpr int Maxl = 3;

struct pos {
    array<int, Maxl> vals{};
    int pnt{0};
};

array<int, Maxl> Shift(const array<int, Maxl>& arr, int pnt) {
    array<int, Maxl> res{};
    for (int i = 0; i + pnt < Maxl; i++)
        res[i + pnt] = arr[i];
    return res;
}

array<int, Maxl> Union(const array<int, Maxl>& A, const array<int, Maxl>& B) {
    array<int, Maxl> res;
    for (int i = 0; i < res.size(); i++)
        res[i] = A[i] + B[i];
    return res;
}

void Create(vector<pos>& st, int v, int l, int r) {
    st[v].vals[0] = r - l + 1;
    if (l < r) {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b, int delt) {
    if (l == a && r == b)
        st[v].pnt += delt;
    else {
        int m = (l + r) / 2;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        st[v].vals = Union(Shift(st[2 * v].vals, st[2 * v].pnt),
            Shift(st[2 * v + 1].vals, st[2 * v + 1].pnt));
    }
}

array<int, Maxl> Get(const vector<pos>& st, int v, int l, int r, int a, int b, int cov) {
    cov += st[v].pnt;
    if (cov >= Maxl)
        return array<int, Maxl>{};
    if (l == a && r == b)
        return Shift(st[v].vals, cov);
    int m = (l + r) / 2;
    if (b <= m)
        return Get(st, 2 * v, l, m, a, b, cov);
    if (m + 1 <= a)
        return Get(st, 2 * v + 1, m + 1, r, a, b, cov);
    return Union(Get(st, 2 * v, l, m, a, m, cov),
        Get(st, 2 * v + 1, m + 1, r, m + 1, b, cov));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

    }
    return 0;
}
