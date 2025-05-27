#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 500005;
const int Maxl = 26;

char tmp[Maxn];
int T;
int q;
ll cnt[2][Maxl], tot[2];

string Read()
{
    scanf("%s", tmp);
    return tmp;
}

bool Check()
{
    int pnt = Maxl - 1;
    while (cnt[1][pnt] == 0)
        pnt--;
    if (pnt > 0) return true;
    return tot[0] == cnt[0][0] && tot[0] < tot[1];
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        fill((ll*)cnt, (ll*)cnt + 2 * Maxl, 0ll);
        tot[0] = tot[1] = 1;
        cnt[0][0] = cnt[1][0] = 1;
        scanf("%d", &q);
        while (q--) {
            int d, k;
            string s;
            scanf("%d %d", &d, &k);
            d--;
            s = Read();
            for (int i = 0; i < s.length(); i++) {
                cnt[d][s[i] - 'a'] += k;
                tot[d] += k;
            }
            printf("%s\n", Check()? "YES": "NO");
        }
    }
	return 0;
}
