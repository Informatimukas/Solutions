#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

constexpr int Maxn = 400005;
constexpr int Maxm = 524288;

struct pos {
    bool has[2][2];
};

int T;
int n;
int a[Maxn];
iii seq[Maxn];
int slen;
bool edge[Maxn][2][2];
pos st[Maxm];

pos Union(const pos &a, const pos &b) {
    pos c;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            c.has[i][j] = false;
            for (int k = 0; k < 2; k++)
                if (a.has[i][k] && b.has[k][j]) {
                    c.has[i][j] = true;
                    break;
                }
        }
    return c;
}

void Create(int v, int l, int r) {
    fill((bool*)st[v].has, (bool*)st[v].has + 2 * 2, false);
    if (l < r) {
        int m = l + r >> 1;
        Create(2 * v, l, m);
        Create(2 * v + 1, m + 1, r);
    }
}

void Update(int v, int l, int r, int x) {
    if (l == r)
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                st[v].has[i][j] = edge[x][i][j];
    else {
        int m = l + r >> 1;
        if (x <= m) Update(2 * v, l, m, x);
        else Update(2 * v + 1, m + 1, r, x);
        st[v] = Union(st[2 * v], st[2 * v + 1]);
    }
}

void setEdge(int a, int b, bool to) {
    int lef = a >= n? 0: 1;
    int rig = b < n? 0: 1;
    edge[a % n][lef][rig] = to;
    Update(1, 0, n - 1, a % n);
}

int Solve() {
    fill((bool*)edge, (bool*)edge + n * 2 * 2, false);
    Create(1, 0, n - 1);
    int l = 0;
    int res = 2000000000;
    for (int r = 0; r < slen; r++) {
        setEdge(seq[r].second.first, seq[r].second.second, true);
        while (l <= r && (st[1].has[0][0] || st[1].has[1][1])) {
            res = min(res, seq[r].first - seq[l].first);
            setEdge(seq[l].second.first, seq[l].second.second, false);
            l++;
        }
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
            scanf("%d", &a[i]);
        if (n % 2 == 0) {
            set <int> S;
            for (int i = 0; i < n; i += 2) {
                vector <int> opt1 = {a[i] + a[i + 1], a[n + i] + a[n + i + 1]};
                vector <int> opt2 = {a[i] + a[n + i + 1], a[n + i] + a[i + 1]};
                sort(opt1.begin(), opt1.end());
                sort(opt2.begin(), opt2.end());
                if (opt1.back() > opt2.back())
                    swap(opt1, opt2);
                S.insert(opt1[0]);
                S.insert(opt1.back());
            }
            printf("%d\n", *S.rbegin() - *S.begin());
            continue;
        }
        if (n == 1) {
            printf("0\n");
            continue;
        }
        slen = 0;
        for (int i = 0; i < n; i++) {
            vector A = {i, i + n};
            vector B = {(i + 1) % n, (i + 1) % n + n};
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    seq[slen++] = {a[A[j]] + a[B[k]], {A[j], B[k]}};
        }
        sort(seq, seq + slen);
        printf("%d\n", Solve());
    }
    return 0;
}
