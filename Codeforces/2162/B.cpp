#include <bits/stdc++.h>
using namespace std;

int main() {
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
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '1')
                res.push_back(i);
        if (res.empty()) {
            cout << "0\n\n";
            continue;
        }
        cout << res.size() << "\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] + 1 << (i + 1 < res.size() ? ' ' : '\n');
    }
    return 0;
}