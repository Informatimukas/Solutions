#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;
ll k;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %lld", &n, &k);
        ll res = 0;
        vector<ll> seq;
        for (int i = 0; i < n; i++) {
            ll a; scanf("%lld", &a);
            for (int j = 0; j < 60; j++)
                if (a & 1ll << j)
                    res++;
                else seq.push_back(1ll << j);
        }
        ranges::sort(seq);
        for (int i = 0; i < seq.size() && seq[i] <= k; i++) {
            res++;
            k -= seq[i];
        }
        printf("%lld\n", res);
    }
    return 0;
}