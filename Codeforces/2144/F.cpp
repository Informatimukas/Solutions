#include <bits/stdc++.h>
using namespace std;

constexpr int K = 2;

struct Vertex {
    int next[K];
    bool output = false;
    int p = -1;
    char pch;
    int match = -1;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

int getInd(char ch) { return ch == '(' ? 1 : 0; }

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = getInd(ch);
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].output = true;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = getInd(ch);
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

int getMatch(int v) {
    if (t[v].match == -1) {
        if (t[v].output)
            return t[v].match = 1;
        t[v].match = v == 0 ? 0 : getMatch(get_link(v));
    }
    return t[v].match;
}

struct pos {
    bool possible{false};
    int prev1{0}, prev2{0};
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<string> s(n);
    for (auto& x : s) {
        cin >> x;
        if (x == "()") {
            cout << "-1\n";
            return 0;
        }
        add_string(x);
    }
    vector dp(k + 1, vector(k / 2 + 1, vector<pos>(t.size())));
    dp[0][0][0].possible = true;
    for (int i = 0; i < k; i++)
        for (int j = 0; j <= min(i, k - i); j++)
            for (int l = 0; l < t.size(); l++)
                if (dp[i][j][l].possible) {
                    if (j + 1 <= k / 2) {
                        int nl = go(l, '(');
                        if (!getMatch(nl))
                            dp[i + 1][j + 1][nl] = {true, j, l};
                    }
                    if (j > 0) {
                        int nl = go(l, ')');
                        if (!getMatch(nl))
                            dp[i + 1][j - 1][nl] = {true, j, l};
                    }
                }
    int curj = 0, curl = -1;
    for (int l = 0; l < t.size(); l++)
        if (dp[k][0][l].possible) {
            curl = l;
            break;
        }
    if (curl != -1) {
        cout << "1\n";
        string res(k, ')');
        int curi = k;
        while (curi > 0) {
            int nj = dp[curi][curj][curl].prev1;
            int nl = dp[curi][curj][curl].prev2;
            if (nj == curj - 1)
                res[curi - 1] = '(';
            curj = nj;
            curl = nl;
            --curi;
        }
        cout << res << "\n";
        cout << n << "\n";
        for (int i = 1; i <= n; i++)
            cout << i << (i + 1 <= n ? ' ' : '\n');
        return 0;
    }
    if (k == 2) {
        cout << "-1\n";
        return 0;
    }
    array<vector<int>, 2> seq;
    array<string, 2> res;
    for (int i = 0; i < k / 2; i++)
        res[0] += "()";
    res[1] = string(k / 2, '(') + string(k / 2, ')');
    for (int i = 0; i < n; i++)
        if (ranges::adjacent_find(s[i]) != s[i].end())
            seq[0].push_back(i);
        else seq[1].push_back(i);
    cout << "2\n";
    for (int i = 0; i < 2; i++) {
        cout << res[i] << "\n";
        cout << seq[i].size() << "\n";
        for (int j = 0; j < seq[i].size(); j++)
            cout << (seq[i][j] + 1) << (j + 1 < seq[i].size() ? ' ' : '\n');
    }
    return 0;
}
