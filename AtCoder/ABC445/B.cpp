#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> s(n);
    size_t mx = 0;
    for (auto& x : s) {
        cin >> x;
        mx = max(mx, x.length());
    }
    for (auto& x : s) {
        int lim = mx - x.length();
        cout << string(lim / 2, '.') << x << string(lim / 2, '.') << "\n";
    }
    return 0;
}
