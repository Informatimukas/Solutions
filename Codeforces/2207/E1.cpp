#include <bits/stdc++.h>
using namespace std;

void Solve(const vector<int>& a) {
    set forb(a.begin(), a.end());
    int cur = a.size();
    int pnt = cur;
    vector<int> b(a.size());
    set<int> rem;
    for (int i = 0; i <= a.size(); i++)
        rem.insert(i);
    for (int i = 0; i < a.size(); i++) {
        if (a[i] > cur) {
            cout << "NO\n";
            return;
        }
        if (a[i] == cur) {
            while (pnt >= 0 && forb.contains(pnt))
                pnt--;
            if (pnt < 0) {
                cout << "NO\n";
                return;
            }
            b[i] = pnt;
            rem.erase(pnt--);
            continue;
        }
        b[i] = cur;
        rem.erase(cur);
        cur = a[i];
        if (rem.empty() || *rem.rbegin() != a[i]) {
            cout << "NO\n";
            return;
        }
        pnt = min(pnt, a[i]);
    }
    cout << "YES\n";
    for (int i = 0; i < b.size(); i++)
        cout << b[i] << (i + 1 < b.size() ? ' ' : '\n');
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
        Solve(a);
    }
    return 0;
}
