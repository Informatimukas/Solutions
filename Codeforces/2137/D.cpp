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
        vector byval(n + 1, vector<int>());
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            byval[x].push_back(i);
        }
        vector<int> res(n);
        bool bad = false;
        int nxt = 0;
        for (int i = 1; i <= n; i++) {
            if (byval[i].size() % i) {
                bad = true;
                break;
            }
            for (int j = 0; j < byval[i].size(); j += i) {
                nxt++;
                for (int k = j; k < j + i; k++)
                    res[byval[i][k]] = nxt;
            }
        }
        if (bad)
            cout << "-1\n";
        else for (int i = 0; i < n; i++)
                cout << res[i] << (i + 1 < n? ' ': '\n');
    }
    return 0;
}