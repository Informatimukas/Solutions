#include <bits/stdc++.h>
using namespace std;

void addLef(vector<int>& BIT, int x, int val) {
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] = val;
}

int getLef(const vector<int>& BIT, int x) {
    int res = 0;
    for (int i = x; i < BIT.size(); i += i & -i)
        res = max(res, BIT[i]);
    return res;
}

void addRig(vector<int>& BIT, int x, int val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] = val;
}

int getRig(const vector<int>& BIT, int x) {
    int res = BIT.size();
    for (int i = x; i > 0; i -= i & -i)
        res = min(res, BIT[i]);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> A(n + 1), lef(n + 1), rig(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> A[i];
        vector<int> lefBIT(n + 1, 0), rigBIT(n + 1, n + 1);
        for (int i = 1; i <= n; i++) {
            lef[i] = getLef(lefBIT, A[i]);
            addLef(lefBIT, A[i], i);
        }
        vector lst(n + 1, n);
        for (int i = n; i >= 1; i--) {
            rig[i] = getRig(rigBIT, A[i]);
            addRig(rigBIT, A[i], i);
            if (lef[i] >= 1 && rig[i] <= n)
                lst[lef[i]] = min(lst[lef[i]], rig[i] - 1);
        }
        for (int i = n - 1; i >= 1; i--)
            lst[i] = min(lst[i], lst[i + 1]);
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << (lst[l] >= r ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}