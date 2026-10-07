#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    ranges::reverse(a);
    set<int> S;
    int res = 0;
    for (auto x : a)
        if (S.insert(x).second)
            res = x;
    cout << res << "\n";
    return 0;
}
