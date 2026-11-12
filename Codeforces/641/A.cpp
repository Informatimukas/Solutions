#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for (auto& x : a)
        cin >> x;
    vector tk(n, false);
    int cur = 0;
    while (0 <= cur && cur < n && !tk[cur]) {
        tk[cur] = true;
        cur += a[cur] * (s[cur] == '>' ? 1 : -1);
    }
    if (0 <= cur && cur < n)
        cout << "IN";
    cout << "FINITE\n";
    return 0;
}
