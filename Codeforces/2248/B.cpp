#include <bits/stdc++.h>
using namespace std;

bool Solve(const vector<int>& a, const vector<int>& b) {
    queue<int> Q;
    int i = 0;
    for (auto x : a) {
        if (i < b.size() && x < b[i]) {
            Q.push(b[i++]);
            continue;
        }
        if (!Q.empty() && Q.front() < x)
            Q.pop();
    }
    return i >= b.size() && Q.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        vector<int> b(m);
        for (auto& x : b)
            cin >> x;
        ranges::sort(a);
        ranges::sort(b);
        cout << (Solve(a, b) ? "YES" : "NO") << "\n";
    }
    return 0;
}
