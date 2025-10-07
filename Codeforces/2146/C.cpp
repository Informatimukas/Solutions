#include <bits/stdc++.h>
using namespace std;

vector<int> Get(const string& s) {
    vector<int> res(s.length());
    int pnt = 0;
    for (int i = 0, j; i < s.length(); i = j) {
        j = i;
        while (j < s.length() && s[i] == s[j])
            j++;
        if (s[i] == '0') {
            if (j - i == 1)
                return {};
            for (int k = j - 1; k >= i; k--)
                res[k] = ++pnt;
        } else for (int k = i; k < j; k++)
            res[k] = ++pnt;
    }
    return res;
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
        auto got = Get(s);
        if (got.empty()) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++)
            cout << got[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
