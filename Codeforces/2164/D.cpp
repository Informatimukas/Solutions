#include <bits/stdc++.h>
using namespace std;

void Solve(string s, string t, int kmax) {
    vector mx(s.length(), 0);
    int cur = s.length() - 1;
    int best = 0;
    for (int i = t.length() - 1; i >= 0; i--) {
        cur = min(cur, i);
        while (cur >= 0 && s[cur] != t[i])
            cur--;
        if (cur < 0 || i - cur > kmax) {
            cout << "-1\n";
            return;
        }
        best = max(best, i - cur);
        mx[cur] = max(mx[cur], i - cur);
    }
    cout << best << "\n";
    for (int z = best; z > 0; z--) {
        for (int i = t.length() - 1; i >= 0; i--)
            if (mx[i] > 0) {
                s[i + 1] = s[i];
                mx[i + 1] = mx[i] - 1;
                mx[i] = 0;
            }
        cout << s << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, kmax;
        cin >> n >> kmax;
        string s, t;
        cin >> s;
        cin >> t;
        Solve(s, t, kmax);
    }
    return 0;
}
