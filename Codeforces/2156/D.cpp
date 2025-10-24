#include <bits/stdc++.h>
using namespace std;

int Ask(int i, int x) {
    if (i == 0)
        return 0;
    cout << "? " << i << " " << x << endl;
    int res;
    cin >> res;
    return res;
}

int Solve(int b, const vector<int>& my) {
    if (my.empty())
        return 0;
    array<vector<int>, 2> has{};
    for (auto& x : my)
        has[Ask(x, 1 << b)].push_back(x);
    if (has[1].size() >= (my.size() + 1) / 2)
        return Solve(b + 1, has[0]);
    return Solve(b + 1, has[1]) | 1 << b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> seq(n);
        iota(seq.begin(), seq.end(), 0);
        int res = Solve(0, seq);
        cout << "! " << res << endl;
    }
    return 0;
}