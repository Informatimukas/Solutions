#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        vector<ii> seq;
        for (int i = 0; i < s.length(); )
            if (s[i] == '0') i++;
            else {
                int j = i;
                while (j < s.length() && s[j] == '1')
                    j++;
                seq.emplace_back(i, j);
                i = j;
            }
        if (seq.empty()) {
            cout << "0\n";
            continue;
        }
        int res = seq.size() * a;
        for (int i = 1; i < seq.size(); i++) {
            int ch = (seq[i].first - seq[i - 1].second) * b;
            if (ch < a) res += ch - a;
        }
        cout << res << "\n";
    }
    return 0;
}
