#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    vector<int> s(n + 1);
    vector<int> best(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        best[s[i]] = max(best[s[i]], p[i]);
    }
    int res = 0;
    for (int i = 1; i <= k; i++) {
        int c;
        cin >> c;
        res += best[s[c]] != p[c];
    }
    cout << res << "\n";
    return 0;
}
