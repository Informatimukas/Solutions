#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int K = 26;
constexpr ll mod = 998244353;

struct Vertex {
    int next[K];
    bool output = false;
    int ending = -1;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];

    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
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
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}

bool get_ending(int v) {
    if (t[v].ending == -1) {
        if (t[v].output)
            return t[v].ending = 1;
        if (v == 0 || t[v].p == 0)
            return t[v].ending = 0;
        t[v].ending = get_ending(get_link(v));
    }
    return t[v].ending;
}

struct matrix {
    vector<vector<ll>> mat;
    matrix(int s, ll diag = 0): mat(s, vector(s, 0ll)) {
        for (int i = 0; i < mat.size(); i++)
            mat[i][i] = diag;
    }
    matrix operator*(const matrix& oth) const {
        matrix res(mat.size());
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat.size(); j++)
                for (int k = 0; k < mat.size(); k++)
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * oth.mat[k][j]) % mod;
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        add_string(s);
    }
    matrix R(t.size(), 1), A(t.size());
    for (int j = 0; j < t.size(); j++)
        for (int l = 0; l < 26; l++) {
            int i = go(j, l + 'a');
            if (get_ending(i))
                continue;
            A.mat[i][j]++;
        }
    while (n) {
        if (n & 1)
            R = R * A;
        n >>= 1;
        A = A * A;
    }
    ll res = 0;
    for (int i = 0; i < t.size(); i++)
        res = (res + R.mat[i][0]) % mod;
    cout << res << "\n";
    return 0;
}
