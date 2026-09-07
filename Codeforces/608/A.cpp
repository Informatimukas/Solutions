#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s;
    cin >> n >> s;
    int res = 0;
    vector<int> mx(s + 1);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mx[a] = max(mx[a], b);
    }
    int cur = 0;
    for (int i = s; i > 0; i--) {
        cur = max(cur, mx[i]);
        cur++;
    }
    cout << cur << "\n";
    return 0;
}
