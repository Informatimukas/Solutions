#include <bits/stdc++.h>
using namespace std;

bool Solve(const vector<int>& a) {
    if (a.empty())
        return true;
    int nim = 0;
    for (auto x : a)
        nim ^= x;
    if (nim == 0)
        return a[0] > 1 && *ranges::min_element(a) == *ranges::max_element(a);
    vector<int> oth;
    for (auto x : a)
        if ((nim ^ x) >= x)
            oth.push_back(x);
    return Solve(oth);
}

int main() {
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
        cout << (Solve(a) ? "Alice" : "Bob") << "\n";
    }
    return 0;
}