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
        vector<int> seq;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                seq.push_back(i);
        if (seq.size() <= 1 || seq.size() > 3 || seq.back() - seq[0] + 1 != seq.size())
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}