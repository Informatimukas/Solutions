#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    vector<string> B;
    string s;
    while (cin >> s)
        B.push_back(s);
    int res = 0;
    for (int i = 0; i < B.size(); i++)
        for (int j = 0; j < B[i].size(); j++)
            if (B[i][j] == '@') {
                int cnt = 0;
                for (int di = -1; di <= 1; di++)
                    for (int dj = -1; dj <= 1; dj++) if (di || dj) {
                        int ni = i + di, nj = j + dj;
                        if (0 <= ni && ni < B.size() && 0 <= nj && nj < B[i].size() &&
                            B[ni][nj] == '@')
                            cnt++;
                    }
                res += cnt < 4;
            }
    cout << res << endl;
    return 0;
}
