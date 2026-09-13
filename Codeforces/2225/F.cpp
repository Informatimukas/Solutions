#include <bits/stdc++.h>
using namespace std;

constexpr int Maxn = 1000005;
constexpr int Maxk = 21;

char s[Maxn];
int slen;
int rnk[Maxn];
int cur[Maxn];
int cnt[Maxn], nxt[Maxn];
bool dif1[Maxn], dif2[Maxn];

int bef[Maxn], plcp[Maxn];
int lcp[Maxn];

void Clear() {
    fill(rnk, rnk + slen, 0);
    fill(cur, cur + slen, 0);
    fill(cnt, cnt + slen, 0);
    fill(nxt, nxt + slen, 0);
    fill(dif1, dif1 + slen, false);
    fill(dif2, dif2 + slen, false);
    fill(bef, bef + slen, 0);
    fill(plcp, plcp + slen, 0);
    fill(lcp, lcp + slen, 0);
}

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        Clear();
        int n, k, l;
        cin >> n >> l >> k;
        string tmp;
        cin >> tmp;
        for (int i = 0; i < n; i++)
            s[i] = tmp[i];
        slen = n;
        if (n / l < k) {
            cout << "NO\n";
            continue;
        }
        buildSA();
        for (int i = 0; i < n; i++)
            rnk[cur[i]] = i;
        calcLCP();
        vector<array<int, Maxk>> mn(slen);
        for (int i = 1; i < slen; i++)
            mn[i][0] = lcp[i];
        for (int j = 1; j < Maxk; j++)
            for (int i = 1 << j; i < slen; i++)
                mn[i][j] = min(mn[i][j - 1], mn[i - (1 << (j - 1))][j - 1]);
        int best = -1;
        int wpos, wlen;
        for (int cpos = 0; cpos < n; cpos++)
            if (cpos / l + (n - cpos) / l >= k && static_cast<int>(cpos > 0) < k && (cpos == 0 || cpos >= l)) {
                int clen = n - cpos;
                if (cpos / l + 1 < k) {
                    int rem = k - cpos / l - 1;
                    clen -= rem * l;
                }
                if (clen < l)
                    continue;
                int p = rnk[cpos];
                for (int j = Maxk - 1; j >= 0; j--)
                    if (1 << j <= p && clen <= mn[p][j])
                        p -= 1 << j;
                if (p > best || p == best && clen > wlen) {
                    best = p;
                    wpos = cpos;
                    wlen = clen;
                }
            }
        if (best == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << tmp.substr(wpos, wlen) << "\n";
    }
    return 0;
}
