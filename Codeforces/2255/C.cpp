#include <bits/stdc++.h>
using namespace std;

void Change(vector<vector<char>>& B) {
    for (auto& row : B)
        for (auto& ch : row)
            ch = ch == '#' ? '.' : '#';
}

struct pos {
    int n;
    vector<vector<char>> B;
    int sumr{0}, sumc{0};
    int blacks;
};

pos Read() {
    int n;
    cin >> n;
    vector B(n, vector<char>(n));
    int cnt = 0;
    for (auto& row : B)
        for (auto& ch : row) {
            cin >> ch;
            if (ch == '#')
                cnt++;
        }
    if (cnt > n * n - cnt)
        Change(B);
    pos p;
    p.blacks = min(cnt, n * n - cnt);
    p.n = n;
    p.B = B;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (p.B[i][j] == '#') {
                p.sumr = (p.sumr + i) % n;
                p.sumc = (p.sumc + j) % n;
            }
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string player;
    cin >> player;
    if (player == "first") {
        int T;
        cin >> T;
        while (T--) {
            pos inp = Read();
            int tr, tc;
            cin >> tr >> tc;
            tr--; tc--;
            int needr = tr * inp.blacks % inp.n;
            int needc = tc * inp.blacks % inp.n;
            bool was = false;
            for (int i = 0; i < inp.n && !was; i++)
                for (int j = 0; j < inp.n && !was; j++)
                    if (inp.B[i][j] == '#') {
                        int remr = (inp.sumr - i + inp.n) % inp.n;
                        int remc = (inp.sumc - j + inp.n) % inp.n;
                        int wr = (needr - remr + inp.n) % inp.n;
                        int wc = (needc - remc + inp.n) % inp.n;
                        if (inp.B[wr][wc] != inp.B[i][j]) {
                            cout << i + 1 << " " << j + 1 << " " << wr + 1 << " " << wc + 1 << "\n";
                            was = true;
                        }
                    }
            if (!was)
                cout << "1 1 1 1\n";
        }
        return 0;
    }
    int T;
    cin >> T;
    while (T--) {
        pos inp = Read();
        int i = 0, j = 0;
        while (i * inp.blacks % inp.n != inp.sumr)
            i++;
        while (j * inp.blacks % inp.n != inp.sumc)
            j++;
        cout << i + 1 << " " << j + 1 << "\n";
    }
    return 0;
}
