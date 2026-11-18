#include <bits/stdc++.h>
using namespace std;

map<array<int, 3>, bool> M;

bool Solve(const vector<int>& a, int x, int l, int r) {
    if (l > r)
        return false;
    int lef = a[l] > x, rig = a[r] > x;
    auto it = M.find({x, lef, rig});
    if (it != M.end())
        return it->second;
    bool win = a[l] > x && !Solve(a, a[l], l + 1, r) || a[r] > x && !Solve(a, a[r], l, r - 1);
    M.insert(make_pair(array{x, lef, rig}, win));
    return win;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    cout << (Solve(a, -1, 0, n - 1) ? "Alice" : "Bob") << "\n";
    return 0;
}
