#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> ii;

const int mod = 1000000007;
const int Maxn = 1000005;
const int Maxd = 3;

int T;
int n;
int p[Maxn];
bool was[Maxn];
vector <int> my[Maxd];
vector <int> seq;
bool tk[Maxn];

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

ii getRes1(int n)
{
    if (n == 3)
        return {1, 0};
    else return {(n - 1) % 3 + (n - 4) / 3, (3 - n % 3) % 3};
}

void Update(int &got, int &ones, int &twos, int n)
{
    if (n == 0) return;
    got += (n - 1) / 3;
    if (n % 3 == 1) ones++;
    else if (n % 3 == 2) twos++;
}

int Gen(int lvl, const vector <int> &nd, int got, int ones, int twos)
{
    if (lvl >= nd.size()) {
        for (int i = 0; i < seq.size(); i++)
            if (!tk[i])
                Update(got, ones, twos, seq[i]);
        int mn = min(ones, twos);
        got += mn;
        if (ones > mn)
            got += (ones - mn) / 3 * 2;
        else got += twos - mn;
        return got;
    } else {
        int res = Maxn;
        for (int i = 0; i < seq.size(); i++)
            if (!tk[i] && nd[lvl] <= seq[i]) {
                tk[i] = true;
                int ngot = got + int(nd[lvl] < seq[i]);
                int nones = ones, ntwos = twos;
                Update(ngot, nones, ntwos, seq[i] - nd[lvl]);
                res = min(res, Gen(lvl + 1, nd, ngot, nones, ntwos));
                tk[i] = false;
            }
        return res;
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &p[i]);
            was[i] = false;
        }
        for (int i = 0; i < Maxd; i++)
            my[i].clear();
        for (int i = 1; i <= n; i++) if (!was[i]) {
            int num = i;
            int cnt = 0;
            while (!was[num]) {
                was[num] = true;
                cnt++;
                num = p[num];
            }
            my[cnt % Maxd].push_back(cnt);
        }
        seq.clear();
        int got = 0, ones = 0, twos = 0;
        for (int i = 0; i < Maxd; i++) {
            sort(my[i].rbegin(), my[i].rend());
            int siz = min(4, int(my[i].size()));
            for (int j = 0; j < siz; j++)
                seq.push_back(my[i][j]);
            for (int j = siz; j < my[i].size(); j++)
                Update(got, ones, twos, my[i][j]);
        }
        fill(tk, tk + seq.size(), false);
        ii tt = getRes1(n);
        int res1 = ll(toPower(3, tt.first)) * toPower(2, tt.second) % mod;
        int res2;
        if (tt.second == 0)
            res2 = Gen(0, {}, got, ones, twos);
        else if (tt.second == 1)
            res2 = min(Gen(0, {1, 1}, got + 1, ones, twos),
                       Gen(0, {2}, got, ones, twos));
        else res2 = min({Gen(0, {1, 1, 1, 1}, got + 2, ones, twos),
                         Gen(0, {1, 1, 2}, got + 1, ones, twos),
                         Gen(0, {2, 2}, got, ones, twos),
                         Gen(0, {1, 3}, got + 1, ones, twos),
                         Gen(0, {4}, got, ones, twos)});
        printf("%d %d\n", res1, res2);
    }
    return 0;
}
