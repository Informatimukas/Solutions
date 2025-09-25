#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr string dirs = "LRDU";
constexpr int dx[] = {-1, 1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

bool Check(const string& s, const ii& forb) {
    ii cur;
    for (auto& ch : s) {
        auto ind = dirs.find(ch);
        ii nxt = {cur.first + dx[ind], cur.second + dy[ind]};
        if (nxt != forb)
            cur = nxt;
    }
    return cur == ii{0, 0};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        vector<ii> pos;
        ii cur;
        for (auto& ch : s) {
            auto ind = dirs.find(ch);
            cur.first += dx[ind];
            cur.second += dy[ind];
            if (cur != ii{0, 0})
                pos.push_back(cur);
        }
        ii res;
        for (auto& p : pos)
            if (Check(s, p)) {
                res = p;
                break;
            }
        cout << res.first << " " << res.second << "\n";
    }
    return 0;
}