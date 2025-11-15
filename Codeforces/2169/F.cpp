#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 998244353;
int root, root_1;
const int root_pw = 1<<19;
const int Maxm = root_pw;

int toPower(int a, int p)
{
    int res = 1;
    while (p) {
        if (p & 1) res = ll(res) * a % mod;
        p >>= 1; a = ll(a) * a % mod;
    }
    return res;
}

int Inv(int x) { return toPower(x, mod - 2); }

void fft (vector <int> &a, bool invert) {
    int n = a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = Inv(n);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}

void Multiply(vector <int> &a, vector <int> &b, int maxk)
{
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    a.resize(n);
    b.resize(n);
    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++)
        a[i] = ll(a[i]) * b[i] % mod;
    fft(a, true);
    while (a.size() > maxk + 1)
        a.pop_back();
}

int C(int n, int k, const vector<int>& fac, const vector<int>& ifac) {
    if (n < 0 || k < 0 || k > n)
        return 0;
    return static_cast<ll>(fac[n]) * ifac[k] % mod * ifac[n - k] % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    root = toPower(3, 1904);
    root_1 = Inv(root);
    int n, m, k;
    cin >> n >> m >> k;
    array<int, 6> cnt{};
    vector<int> fac(2 * n + 1), ifac(2 * n + 1);
    fac[0] = ifac[0] = 1;
    for (int i = 1; i < fac.size(); i++) {
        fac[i] = static_cast<ll>(i) * fac[i - 1] % mod;
        ifac[i] = Inv(fac[i]);
    }
    int res = 1;
    int tot = 0;
    for (int i = 0; i < k; i++) {
        int l;
        cin >> l;
        res = static_cast<ll>(res) * fac[l] % mod;
        tot += l;
        for (int j = 1; j <= l; j++)
            cnt[j]++;
    }
    cnt[0]++;
    int maxk = n - tot;
    vector ans = {res};
    for (int j = 0; j < cnt.size(); j++)
        if (cnt[j]) {
            vector<int> seq(maxk + 1);
            int cur = 1;
            for (int i = 0; i <= maxk; i++) {
                seq[i] = static_cast<ll>(cur) * C(i + cnt[j] - 1, i, fac, ifac) % mod;
                cur = static_cast<ll>(cur) * (m - j) % mod;
            }
            Multiply(ans, seq, maxk);
        }
    cout << ans[maxk] << "\n";
    return 0;
}
