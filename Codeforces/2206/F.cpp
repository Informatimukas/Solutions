#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 998244353;
int root, root_1;
const int root_pw = 1<<20;
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

void Multiply(vector <int> &a, vector <int> &b)
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
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    root = toPower(3, 952);
    root_1 = Inv(root);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> divs(n);
    for (int i = 1; i < n; i++)
        for (int j = i; j < n; j += i)
            divs[j].push_back(i);
    int all = 0;
    vector f(n + 1, 0);
    for (int i = 0; i < n; i++)
        if (s[i] == '0') {
            if (i > 0) {
                int got = s[i - 1] - '0';
                all += got;
                for (int d : divs[i])
                    f[d] -= got;
            }
            if (i + 1 < n) {
                int got = s[i + 1] - '0';
                all += got;
                for (int d : divs[i + 1])
                    f[d] -= got;
            }
        }
    // from right
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            a[n - 1 - i] = 1;
        b[i] = s[i] - '0';
    }
    Multiply(a, b);
    for (int i = 1; i <= n && i + n - 1 < a.size(); i++)
        f[i] += a[i + n - 1];
    // from left
    a = vector(n, 0);
    b = vector(n, 0);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0')
            a[i] = 1;
        b[n - 1 - i] = s[i] - '0';
    }
    Multiply(a, b);
    for (int i = 1; i <= n && i + n - 1 < a.size(); i++)
        f[i] += a[i + n - 1];
    nth_element(f.begin() + 1, f.begin() + k, f.end(), greater());
    cout << f[k] + all << "\n";
    return 0;
}
