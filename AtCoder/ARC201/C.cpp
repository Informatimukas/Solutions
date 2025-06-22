#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int mod = 998244353;

struct trie {
    int cnt;
    bool en;
    int ways;
    trie *ch[2];
    trie() {
        cnt = 0;
        en = false;
        ways = 0;
        ch[0] = ch[1] = NULL;
    }
};

char tmp[Maxn];
int pw2[Maxn];
int n;
string S[Maxn];
int res;

int getWays(trie *tr) { return tr? tr->ways : 0; }

void Add(trie *tr, int lvl, const string &str) {
    tr->cnt++;
    if (lvl >= str.length()) tr->en = true;
    else {
        int ind = str[lvl] - 'A';
        if (!tr->ch[ind]) tr->ch[ind] = new trie();
        Add(tr->ch[ind], lvl + 1, str);
    }
    tr->ways = ll(getWays(tr->ch[0])) * getWays(tr->ch[1]) % mod;
    if (tr->en) tr->ways = (tr->ways + ll(pw2[tr->cnt - 1])) % mod;
}

string Read() {
    scanf("%s", tmp);
    return tmp;
}

int main() {
    pw2[0] = 1;
    for (int i = 1; i < Maxn; i++)
        pw2[i] = 2ll * pw2[i - 1] % mod;
    scanf("%d", &n);
    trie *root = new trie();
    for (int i = 0; i < n; i++) {
        string s = Read();
        Add(root, 0, s);
        printf("%d\n", getWays(root));
    }
    return 0;
}