#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n < 6) {
            for (int i = 1; i <= n; i++)
                cout << i << (i + 1 <= n ? ' ' : '\n');
            continue;
        }
        vector tk(n + 1, false);
        tk[6] = true;
        vector<int> spec;
        for (int i = 2; i <= n; i += 2)
            if (!tk[i]) {
                tk[i] = true;
                spec.push_back(i);
            }
        spec.push_back(6);
        for (int i = 3; i <= n; i += 3)
            if (!tk[i]) {
                tk[i] = true;
                spec.push_back(i);
            }
        vector<int> oth;
        for (int i = 1; i <= n; i++)
            if (!tk[i])
                oth.push_back(i);
        vector<int> res;
        for (int i = 0; !spec.empty() || !oth.empty(); i = (i + 1) % 3)
            if (i && !spec.empty()) {
                res.push_back(spec.back());
                spec.pop_back();
            } else if (!i && !oth.empty()) {
                res.push_back(oth.back());
                oth.pop_back();
            }
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}
