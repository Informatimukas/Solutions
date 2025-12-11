#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Inf = 1000000000;

struct matrix {
    vector<vector<ll>> B;
    vector<int> my;
    vector<int> free;
    vector<ll> vals;
    matrix() = delete;
    explicit matrix(vector<vector<ll>> board): B(std::move(board)), vals(B[0].size() - 1) {}
    void changeSigns(int r) {
        for (auto& j : B[r])
            j = -j;
    }
    void Eliminate(int r1, int r2, int c) {
        if (B[r2][c] == 0)
            return;
        if (B[r2][c] < 0)
            changeSigns(r2);
        ll lcm = B[r1][c] / __gcd(B[r1][c], B[r2][c]) * B[r2][c];
        ll mult1 = lcm / B[r1][c];
        ll mult2 = lcm / B[r2][c];
        for (int j = c; j < B[r2].size(); j++)
            B[r2][j] = B[r2][j] * mult2 - B[r1][j] * mult1;
    }
    void Solve() {
        int j = 0;
        for (int i = 0; i < B.size(); i++) {
            while (j + 1 < B[i].size()) {
                bool has = false;
                for (int k = i; k < B.size(); k++)
                    if (B[k][j]) {
                        has = true;
                        swap(B[i], B[k]);
                        break;
                    }
                if (!has)
                    free.push_back(j++);
                else break;
            }
            if (j + 1 >= B[i].size())
                break;
            if (B[i][j] < 0)
                changeSigns(i);
            for (int k = i + 1; k < B.size(); k++)
                Eliminate(i, k, j);
            my.push_back(j++);
        }
        while (j + 1 < B[0].size())
            free.push_back(j++);
    }
    ll backTrack(int lvl, ll cur) {
        if (lvl >= free.size()) {
            for (int i = my.size() - 1; i >= 0; i--) {
                int v = my[i];
                ll z = B[i].back();
                for (int j = B[i].size() - 2; j > v; j--)
                    z -= B[i][j] * vals[j];
                if (z % B[i][v])
                    return Inf;
                vals[v] = z / B[i][v];
                if (vals[v] < 0)
                    return Inf;
                cur += vals[v];
            }
            return cur;
        }
        ll res = Inf;
        for (int i = 0; i <= 300; i++) {
            vals[free[lvl]] = i;
            res = min(res, backTrack(lvl + 1, cur + i));
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    string s;
    ll res = 0;
    while (getline(cin, s)) {
        cout << "solving " << s << endl;
        stringstream ss(s);
        vector<int> seq;
        vector<int> a;
        while (ss >> s)
            if (s[0] == '{') {
                for (auto& ch : s)
                    if (!isdigit(ch))
                        ch = ' ';
                stringstream ss2(s);
                int num;
                while (ss2 >> num)
                    seq.push_back(num);
            } else if (s[0] == '(') {
                for (auto& ch : s)
                    if (!isdigit(ch))
                        ch = ' ';
                stringstream ss2(s);
                int num, cur = 0;
                while (ss2 >> num)
                    cur |= 1 << num;
                a.push_back(cur);
            }
        vector B(seq.size(), vector<ll>(a.size() + 1));
        for (int i = 0; i < seq.size(); i++)
            B[i][a.size()] = seq[i];
        for (int i = 0; i < seq.size(); i++)
            for (int j = 0; j < a.size(); j++)
                B[i][j] = (a[j] & 1 << i) ? 1 : 0;
        matrix M(B);
        M.Solve();
        cout << "final board" << endl;
        for (int i = 0; i < B.size(); i++)
            for (int j = 0; j < B[i].size(); j++)
                cout << M.B[i][j] << (j + 1 < B[i].size() ? ' ' : '\n');
        cout << "my = " << endl;
        for (int i = 0; i < M.my.size(); i++)
            cout << " " << M.my[i];
        cout << endl;
        cout << "free = " << endl;
        for (int i = 0; i < M.free.size(); i++)
            cout << " " << M.free[i];
        cout << endl;
        ll got = M.backTrack(0, 0ll);
        cout << "got = " << got << endl;
        res += got;
    }
    cout << "tot res = " << res << endl;
    return 0;
}
