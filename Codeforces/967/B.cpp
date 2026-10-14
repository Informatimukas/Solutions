#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> s(n);
    for (auto& x : s)
        cin >> x;
    int S = s[0] * a / b;
    S -= s[0];
    s.erase(s.begin());
    ranges::sort(s);
    int res = 1;
    for (auto x : s)
        if (x <= S) {
            S -= x;
            res++;
        }
    cout << n - res << "\n";
    return 0;
}
