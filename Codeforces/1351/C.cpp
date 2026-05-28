#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using iiii = pair<ii, ii>;

bool Add(set<iiii>& S, ii a, ii b) {
    if (a > b)
        swap(a, b);
    return S.insert({a, b}).second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        set<iiii> S;
        string s;
        cin >> s;
        ii cur = {0, 0};
        int res = 0;
        for (auto ch : s) {
            ii nxt = cur;
            if (ch == 'S')
                nxt.first++;
            else if (ch == 'N')
                nxt.first--;
            else if (ch == 'E')
                nxt.second++;
            else if (ch == 'W')
                nxt.second--;
            res += Add(S, cur, nxt) ? 5 : 1;
            cur = nxt;
        }
        cout << res << "\n";
    }
    return 0;
}
