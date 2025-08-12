#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

void addLeft(vector<int>& BIT, int x, int val) {
    for (int i = x; i < BIT.size(); i += i & -i)
        BIT[i] = max(BIT[i], val);
}

int getLeft(const vector<int>& BIT, int x) {
    int res = 0;
    for (int i = x; i > 0; i -= i & -i)
        res = max(res, BIT[i]);
    return res + 1;
}

void addRight(vector<int>& BIT, int x, int val) {
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] = min(BIT[i], val);
}

int getRight(const vector<int>& BIT, int x) {
    int res = BIT.size();
    for (int i = x; i < BIT.size(); i += i & -i)
        res = min(res, BIT[i]);
    return res - 1;
}

vector<int> Solve(const vector<int>& a, const vector<int>& b) {
    vector<int> lefBIT(a.size(), 0), rigBIT(a.size(), a.size());
    vector<int> lef(a.size()), rig(a.size()), my(a.size());
    for (int i = 1; i < b.size(); i++)
        if (b[i]) my[b[i]] = i;
    for (int i = 1; i < a.size(); i++) {
        lef[a[i]] = getLeft(lefBIT, a[i]);
        if (my[a[i]]) addLeft(lefBIT, a[i], my[a[i]]);
    }
    for (int i = a.size() - 1; i > 0; i--) {
        rig[a[i]] = getRight(rigBIT, a[i]);
        if (my[a[i]]) addRight(rigBIT, a[i], my[a[i]]);
    }
    vector<vector<ii>> quer(b.size());
    for (int i = 1; i < a.size(); i++) {
        if (lef[i] > rig[i]) return {-1};
        if (my[i] && (my[i] < lef[i] || my[i] > rig[i]))
            return {-1};
        if (!my[i]) quer[lef[i]].emplace_back(rig[i], i);
    }
    priority_queue<ii, vector<ii>, greater<>> Q;
    vector<int> res;
    for (int i = 1; i < b.size(); i++) {
        for (auto& p : quer[i])
            Q.push(p);
        if (b[i]) res.push_back(b[i]);
        else if (Q.empty()) return {-1};
        else {
            ii p = Q.top();
            Q.pop();
            if (i > p.first) return {-1};
            res.push_back(p.second);
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i < a.size(); i++)
            cin >> a[i];
        vector<int> b(n + 1);
        for (int i = 1; i < b.size(); i++)
            cin >> b[i];
        auto res = Solve(a, b);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size()? ' ': '\n');
    }
    return 0;
}