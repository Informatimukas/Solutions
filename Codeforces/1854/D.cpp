#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 1000000000;
constexpr int Maxp = 125;

int Ask(int v, int k, const set<int>& S) {
    cout << "? " << v << " " << k << " " << S.size();
    for (auto& x : S)
        cout << " " << x;
    cout << endl;
    int res;
    cin >> res;
    return res;
}

void Print(const set<int>& S) {
    cout << "! " << S.size();
    for (auto& x : S)
        cout << " " << x;
    cout << endl;
}

set<int> getSet(int l, int r) {
    set<int> S;
    for (int i = l; i <= r; i++)
        S.insert(i);
    return S;
}

int getValue(int v, int k, int n) {
    int lef = 1, rig = n;
    while (lef < rig) {
        int mid = (lef + rig) / 2;
        if (Ask(v, k, getSet(lef, mid)))
            rig = mid;
        else lef = mid + 1;
    }
    return lef;
}

int getStatus(int n, set<int>& S) {
    int v = getValue(1, lim, n);
    S.insert(v);
    for (int i = 2; i <= Maxp; i++) {
        int u = getValue(v, 1, n);
        if (!S.insert(u).second)
            return 0;
        v = u;
    }
    return S.contains(getValue(v, Maxp, n)) ? 1 : 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    set<int> S;
    int st = getStatus(n, S);
    S.insert(1);
    if (st >= 1)
        for (int i = 1; i <= n; i++)
            if (!S.contains(i) && Ask(i, Maxp, S))
                S.insert(i);
    if (st >= 2)
        for (int i = 1; i <= n; i++)
            if (!S.contains(i) && Ask(i, 2 * Maxp, S))
                S.insert(i);
    for (int i = 1; i <= n; i++)
        if (!S.contains(i) && Ask(i, lim, S))
            S.insert(i);
    Print(S);
    return 0;
}
