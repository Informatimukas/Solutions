#include <bits/stdc++.h>
using namespace std;

bool Solve(string s, vector<int>& res) {
    for (int z = 0; z < 2; z++) {
        res.clear();
        for (int i = 0; i < s.length(); i++)
            if (s[i] - '0' != z)
                res.push_back(i);
        if (res.size() % 2 == z)
            return true;
    }
    return false;
}

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
        vector<int> res;
        if (Solve(s, res)) {
            cout << res.size() << "\n";
            for (int i = 0; i < res.size(); i++)
                cout << res[i] + 1 << (i + 1 < res.size() ? ' ' : '\n');
        } else cout << "-1\n";
    }
    return 0;
}
