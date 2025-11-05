#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        vector<int> cur;
        vector<vector<int>> res;
        int n, w;
        cin >> n >> w;
        int nxt = 1;
        int step = 1 << (n - 1);
        while (nxt < w) {
            for (int i = 0; i < step; i++) {
                if (nxt == w)
                    nxt++;
                cur.push_back(nxt++);
            }
            step /= 2;
        }
        cur.push_back(w);
        if (nxt == w)
            nxt++;
        while (nxt <= 1 << n)
            cur.push_back(nxt++);
        res.push_back(cur);
        while (cur.size() != 1) {
            vector<int> nw;
            for (int i = 0; i < cur.size(); i += 2)
                if (cur[i] == w || cur[i + 1] == w)
                    nw.push_back(w);
                else nw.push_back(min(cur[i], cur[i + 1]));
            res.push_back(nw);
            cur = std::move(nw);
        }
        for (int i = res.size() - 1; i >= 0; i--)
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << (i > 0 || j + 1 < res[i].size() ? ' ' : '\n');
    }
    return 0;
}
