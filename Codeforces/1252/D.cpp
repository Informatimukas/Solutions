#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

constexpr int Maxn = 500005;
constexpr int Maxm = 1048576;
constexpr int Maxk = 21;

struct SuffixArray {
    char s[Maxn];
    int slen;
    int rnk[Maxn];
    int cur[Maxn];
    int cnt[Maxn], nxt[Maxn];
    bool dif1[Maxn], dif2[Maxn];

    int bef[Maxn], plcp[Maxn];
    int lcp[Maxn];
    int mx[Maxn][Maxk];

    SuffixArray() {
        fill_n(s, Maxn, 0);
        slen = 0;
        fill_n(rnk, Maxn, 0);
        fill_n(cur, Maxn, 0);
        fill_n(cnt, Maxn, 0);
        fill_n(nxt, Maxn, 0);
        fill_n(dif1, Maxn, 0);
        fill_n(dif2, Maxn, 0);
        fill_n(bef, Maxn, 0);
        fill_n(plcp, Maxn, 0);
        fill_n(lcp, Maxn, 0);
        for (int i = 0; i < Maxn; i++)
            fill_n(mx[i], Maxk, 0);
    }

    void buildSA()
    {
        for (int i = 0; i < slen; i++)
            cur[i] = i;
        sort(cur, cur + slen, [&](int a, int b) {
            return s[a] < s[b];
        });
        for (int i = 0; i < slen; i++) {
            dif1[i] = i == 0 || s[cur[i - 1]] != s[cur[i]];
            dif2[i] = false;
        }
        for (int h = 1; h < slen; h <<= 1) {
            int buck = 0;
            for (int i = 0, j; i < slen; i = j) {
                j = i + 1;
                while (j < slen && !dif1[j]) j++;
                nxt[i] = j;
                buck++;
            }
            if (buck == slen) break;
            for (int i = 0; i < slen; i = nxt[i]) {
                cnt[i] = 0;
                for (int j = i; j < nxt[i]; j++)
                    rnk[cur[j]] = i;
            }
            cnt[rnk[slen - h]]++; dif2[rnk[slen - h]] = true;
            for (int i = 0; i < slen; i = nxt[i]) {
                for (int j = i; j < nxt[i]; j++) {
                    int s = cur[j] - h;
                    if (s >= 0) {
                        int head = rnk[s];
                        rnk[s] = head + cnt[head]++;
                        dif2[rnk[s]] = true;
                    }
                }
                for (int j = i; j < nxt[i]; j++) {
                    int s = cur[j] - h;
                    if (s >= 0 && dif2[rnk[s]])
                        for (int k = rnk[s] + 1; !dif1[k] && dif2[k]; k++) dif2[k] = false;
                }
            }
            for (int i = 0; i < slen; i++) {
                cur[rnk[i]] = i;
                dif1[i] |= dif2[i];
            }
        }
    }

    void calcLCP()
    {
        bef[cur[0]] = -1;
        for (int i = 1; i < slen; i++) bef[cur[i]] = cur[i - 1];
        int l = 0;
        for (int i = 0; i < slen; i++) if (bef[i] != -1) {
            while (bef[i] + l < slen && i + l < slen && s[bef[i] + l] == s[i + l]) l++;
            plcp[i] = l;
            l = max(l - 1, 0);
        }
        for (int i = 0; i < slen; i++)
            lcp[i] = plcp[cur[i]];
    }

    void Solve() {
        buildSA();
        for (int i = 0; i < slen; i++)
            rnk[cur[i]] = i;
        calcLCP();
        for (int i = 0; i + 1 < slen; i++)
            mx[i][0] = lcp[i + 1];
        for (int j = 1; j < Maxk; j++)
            for (int i = 0; i + (1 << j) < slen; i++)
                mx[i][j] = min(mx[i][j - 1], mx[i + (1 << j - 1)][j - 1]);
    }

    int GetLeft(int ind, int nd) {
        for (int j = Maxk - 1; j >= 0; j--)
            if (ind - (1 << j) >= 0 && mx[ind - (1 << j)][j] >= nd)
                ind -= 1 << j;
        return ind;
    }

    int GetRight(int ind, int nd) {
        for (int j = Maxk - 1; j >= 0; j--)
            if (ind + (1 << j) < slen && mx[ind][j] >= nd)
                ind += 1 << j;
        return ind;
    }
};

constexpr int Maxr = 505;

char tmp[Maxn];
int R, C, Q;
char B[Maxr][Maxr];
string str[Maxn];
vector<int> cid[Maxn], rid[Maxn];
vector<ii> querCol[Maxn], querRow[Maxn];
vector<int> seq[Maxm];
SuffixArray sarows, sacols;

string readString() {
    scanf("%s", tmp);
    return tmp;
}

void Add(int v, int l, int r, int x, int val) {
    seq[v].push_back(val);
    if (l < r) {
        int m = l + r >> 1;
        if (x <= m)
            Add(2 * v, l, m, x, val);
        else Add(2 * v + 1, m + 1, r, x, val);
    }
}

int Count(int v, int l, int r, int a, int b, int lef, int rig) {
    if (l == a && r == b)
        return ranges::upper_bound(seq[v], rig) -
               ranges::lower_bound(seq[v], lef);
    int res = 0;
    int m = l + r >> 1;
    if (a <= m) res += Count(2 * v, l, m, a, min(m, b), lef, rig);
    if (m + 1 <= b) res += Count(2 * v + 1, m + 1, r, max(m + 1, a), b, lef, rig);
    return res;
}

void solveCols() {
    for (int j = 0; j < C; j++) {
        for (int i = 0; i < R; i++)
            sacols.s[sacols.slen++] = B[i][j];
        sacols.s[sacols.slen++] = '#';
    }
    for (int i = 0; i < Q; i++) {
        cid[i].resize(str[i].length());
        for (int j = 0; j < str[i].length(); j++) {
            cid[i][j] = sacols.slen;
            sacols.s[sacols.slen++] = str[i][j];
        }
    }
    sacols.Solve();
    for (int i = 0; i < Q; i++) {
        querCol[i].resize(str[i].length());
        for (int j = 0; j < str[i].length(); j++) {
            int r = sacols.rnk[cid[i][j]];
            querCol[i][j] = {sacols.GetLeft(r, str[i].length() - j),
                                sacols.GetRight(r, str[i].length() - j)};
        }
    }
}

void solveRows() {
    for (int i = 0; i < R; i++) {
        for (int j = C - 1; j >= 0; j--)
            sarows.s[sarows.slen++] = B[i][j];
        sarows.s[sarows.slen++] = '#';
    }
    for (int i = 0; i < Q; i++) {
        rid[i].resize(str[i].length());
        for (int j = str[i].length() - 1; j >= 0; j--) {
            rid[i][j] = sarows.slen;
            sarows.s[sarows.slen++] = str[i][j];
        }
    }
    sarows.Solve();
    for (int i = 0; i < Q; i++) {
        querRow[i].resize(str[i].length());
        for (int j = str[i].length() - 1; j >= 0; j--) {
            int r = sarows.rnk[rid[i][j]];
            querRow[i][j] = {sarows.GetLeft(r, j + 1),
                                sarows.GetRight(r, j + 1)};
        }
    }
}

int main() {
    scanf("%d %d %d", &R, &C, &Q);
    for (int i = 0; i < R; i++)
        scanf("%s", B[i]);
    for (int i = 0; i < Q; i++)
        str[i] = readString();
    solveCols();
    solveRows();
    for (int i = 0; i < sacols.slen; i++) {
        int ind = sacols.cur[i];
        int col = ind / (R + 1);
        int row = ind % (R + 1);
        if (row < R && col < C) {
            int ind2 = row * (C + 1) + C - 1 - col;
            int r = sarows.rnk[ind2];
            Add(1, 0, sarows.slen - 1, r, i);
        }
    }
    for (int i = 0; i < Q; i++) {
        ll res = 0;
        for (int j = 0; j < str[i].length(); j++) {
            res += Count(1, 0, sarows.slen - 1,
                querRow[i][j].first, querRow[i][j].second,
                querCol[i][j].first, querCol[i][j].second);
        }
        printf("%lld\n", res);
    }
    return 0;
}