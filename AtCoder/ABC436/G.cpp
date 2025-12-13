#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long ll;
#define SZ 233333
const int MOD=998244353;

ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
namespace linear_seq {
inline vector<int> BM(vector<int> x)
{
	//ls: (shortest) relation sequence (after filling zeroes) so far
	//cur: current relation sequence
	vector<int> ls,cur;
	//lf: the position of ls (t')
	//ld: delta of ls (v')
	int lf,ld;
	for(int i=0;i<int(x.size());++i)
	{
		ll t=0;
		//evaluate at position i
		for(int j=0;j<int(cur.size());++j)
			t=(t+x[i-j-1]*(ll)cur[j])%MOD;
		if((t-x[i])%MOD==0) continue; //good so far
		//first non-zero position
		if(!cur.size())
		{
			cur.resize(i+1);
			lf=i; ld=(t-x[i])%MOD;
			continue;
		}
		//cur=cur-c/ld*(x[i]-t)
		ll k=-(x[i]-t)*qp(ld,MOD-2)%MOD/*1/ld*/;
		vector<int> c(i-lf-1); //add zeroes in front
		c.pb(k);
		for(int j=0;j<int(ls.size());++j)
			c.pb(-ls[j]*k%MOD);
		if(c.size()<cur.size()) c.resize(cur.size());
		for(int j=0;j<int(cur.size());++j)
			c[j]=(c[j]+cur[j])%MOD;
		//if cur is better than ls, change ls to cur
		if(i-lf+(int)ls.size()>=(int)cur.size())
			ls=cur,lf=i,ld=(t-x[i])%MOD;
		cur=c;
	}
	for(int i=0;i<int(cur.size());++i)
		cur[i]=(cur[i]%MOD+MOD)%MOD;
	return cur;
}
int m; //length of recurrence
//a: first terms
//h: relation
ll a[SZ],h[SZ],t_[SZ],s[SZ],t[SZ];

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

//calculate p*q mod f
inline void mull(ll*p,ll*q)
{
	for(int i=0;i<m+m;++i) t_[i]=0;
	vector<int> A(m, 0), B(m, 0);
	for (int i = 0; i < m; i++) {
		A[i] = p[i];
		B[i] = q[i];
	}
	Multiply(A, B);
	for (int i = 0; i < m; i++)
		A[i] = 0;
	for (int i = 0; i < m; i++)
		B[i] = h[m - 1 - i];
	Multiply(A, B);
	for(int i=0;i<m;++i) p[i]=A[i + m+m-1];
}
inline ll calc(ll K)
{
	for(int i=m;~i;--i)
		s[i]=t[i]=0;
	//init
	s[0]=1; if(m!=1) t[1]=1; else t[0]=h[0];
	//binary-exponentiation
	while(K)
	{
		if(K&1) mull(s,t);
		mull(t,t); K>>=1;
	}
	ll su=0;
	for(int i=0;i<m;++i) su=(su+s[i]*a[i])%MOD;
	return (su%MOD+MOD)%MOD;
}
inline int work(vector<int> x,ll n)
{
	if(n<int(x.size())) return x[n];
	vector<int> v=BM(x); m=v.size(); if(!m) return 0;
	for(int i=0;i<m;++i) h[i]=v[i],a[i]=x[i];
	return calc(n);
}
}
using linear_seq::work;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	linear_seq::root = linear_seq::toPower(3, 1904);
	linear_seq::root_1 = linear_seq::Inv(linear_seq::root);
	int n;
	ll m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& x : a)
		cin >> x;
	vector seq(15005, 0);
	seq[0] = 1;
	for (auto& x : a)
		for (int j = 0; j + x < seq.size(); j++)
			seq[j + x] = (seq[j + x] + seq[j]) % MOD;
	for (int i = 1; i < seq.size(); i++)
		seq[i] = (seq[i] + seq[i - 1]) % MOD;
	cout << work(seq, m) << "\n";
    return 0;
}
