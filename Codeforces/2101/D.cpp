#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int Collect(int i, int lef, const vector<vector<int>>& jump) {
    int cur = i;
    int res = 0;
    for (int j = static_cast<int>(jump[i].size()) - 1; j >= 0; j--)
        if (jump[cur].size() > j && jump[cur][j] >= lef) {
            res += 1 << j;
            cur = jump[cur][j];
        }
    return res;
}

void addBigBIT(vector<int>& BIT, int x, int val) {
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] = val;
}

int getBigBIT(const vector<int>& BIT, int x) {
    int res = -1;
    for (int i = x; i < BIT.size(); i += i & -i)
        res = max(res, BIT[i]);
    return res;
}

void addSmallBIT(vector<int>& BIT, int x, int val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] = val;
}

int getSmallBIT(const vector<int>& BIT, int x) {
    int res = -1;
    for (int i = x; i > 0; i -= i & -i)
        res = max(res, BIT[i]);
    return res;
}

vector<int> getSides(const vector<int>& a) {
    map<int, int> M;
    vector<int> res(a.size());
    vector bigger(a.size(), vector<int>());
    vector smaller(a.size(), vector<int>());
    vector smallBIT(a.size() + 1, -1), bigBIT(a.size() + 1, -1);
    for (int i = 0; i < a.size(); i++) {
        int ind = getBigBIT(bigBIT, a[i]);
        if (ind != -1) {
            bigger[i].push_back(ind);
            for (int j = 0; j < bigger[bigger[i][j]].size(); j++)
                bigger[i].push_back(bigger[bigger[i][j]][j]);
        }
        addBigBIT(bigBIT, a[i], i);
        ind = getSmallBIT(smallBIT, a[i]);
        if (ind != -1) {
            smaller[i].push_back(ind);
            for (int j = 0; j < smaller[smaller[i][j]].size(); j++)
                smaller[i].push_back(smaller[smaller[i][j]][j]);
        }
        addSmallBIT(smallBIT, a[i], i);
        M.emplace(a[i], i);
        int lef = 0, rig = i - 1;
        while (lef <= rig) {
            int mid = (lef + rig) / 2;
            if (Collect(i, mid, bigger) + Collect(i, mid, smaller) == i - mid)
                rig = mid - 1;
            else lef = mid + 1;
        }
        res[i] = lef;
    }
    return res;
}

struct pos {
    int siz, my;
    int tot;
    int Get() { return my > 0 ? siz : tot; }
};

void Create(vector<pos>& st, int v, int l, int r) {
    st[v].siz = r - l + 1;
    st[v].my = st[v].tot = 0;
    if (l < r) {
        int m = (l + r) / 2;
        Create(st, 2 * v, l, m);
        Create(st, 2 * v + 1, m + 1, r);
    }
}

void Update(vector<pos>& st, int v, int l, int r, int a, int b, int delt) {
    if (l == a && r == b)
        st[v].my += delt;
    else {
        int m = l + r >> 1;
        if (a <= m)
            Update(st, 2 * v, l, m, a, min(m, b), delt);
        if (m + 1 <= b)
            Update(st, 2 * v + 1, m + 1, r, max(m + 1, a), b, delt);
        st[v].tot = st[2 * v].Get() + st[2 * v + 1].Get();
    }
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> L = getSides(a);
        ranges::reverse(a);
        vector<int> R = getSides(a);
        ranges::reverse(R);
        for (int i = 0; i < n; i++)
            R[i] = n - 1 - R[i];
        vector add(n + 1, vector<ii>());
        vector rem(n + 1, vector<ii>());
        for (int i = 0; i < n; i++) {
            add[L[i]].emplace_back(i, R[i]);
            rem[i + 1].emplace_back(i, R[i]);
        }
        vector<pos> st(4 * n);
        Create(st, 1, 0, n - 1);
        long long res = 0;
        for (int i = 0; i < n; i++) {
            for (auto& [a, b] : add[i])
                Update(st, 1, 0, n - 1, a, b, 1);
            for (auto& [a, b] : rem[i])
                Update(st, 1, 0, n - 1, a, b, -1);
            res += st[1].Get();
        }
        cout << res << "\n";
    }
    return 0;
}
