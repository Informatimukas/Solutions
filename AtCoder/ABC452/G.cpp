#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int Maxn = 500005;
constexpr int Maxm = 21;

char s[Maxn];
int slen;
int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];

int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

bool Less(const int &a, const int &b) { return s[a] < s[b]; }

void buildSA()
{
    for (int i = 0; i < slen; i++)
        cur[i] = i;
    sort(cur, cur + slen, Less);
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

bool Check(int l, int r, char ch) {
    for (int i = l; i <= r; i++)
        if (s[i] != ch)
            return false;
    return true;
}

ll getUntil(int st, int en, const vector<vector<int>>& step, const vector<int>& count) {
    int lim = count[st];
    int res = 0;
    for (int i = Maxm - 1; i >= 0; i--)
        if (step[st][i] <= en) {
            res += 1 << i;
            st = step[st][i];
        }
    return min(lim, res);
}

int main()
{
    int n;
    cin >> n;
    slen = n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s[i] = a + '0';
    }
    buildSA();
    calcLCP();
    vector step(n + 1, vector(Maxm, Maxn));
    vector count(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int nd = s[i] - '0';
        if (i + nd <= n && Check(i, i + nd - 1, s[i])) {
            step[i][0] = i + nd;
            count[i]++;
            if (step[i][0] == n || s[step[i][0]] != s[i]) {
                count[i] += count[step[i][0]];
                for (int j = 1; j < Maxm; j++)
                    if (step[i][j - 1] <= n)
                        step[i][j] = step[step[i][j - 1]][j - 1];
            }
        }
    }
    ll res = 0;
    for (int i = 0; i < slen; i++) {
        res += getUntil(cur[i], n, step, count) - getUntil(cur[i], cur[i] + lcp[i], step, count);
    }
    cout << res << "\n";
    return 0;
}