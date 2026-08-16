#include <bits/stdc++.h>
using namespace std;

using ic = pair<int, char>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<ic> res;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && s[i] == s[j])
                j++;
            res.emplace_back(j - i, s[i]);
        }
        int mx = 0;
        for (int i = 1; i + 1 < res.size(); i++)
            if (res[i].first == 1) {
                int cand = 1;
                if (res[i - 1].second == res[i + 1].second)
                    cand++;
                mx = max(mx, cand);
            }
        cout << res.size() - mx << "\n";
    }
    return 0;
}
