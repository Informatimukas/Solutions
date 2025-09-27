#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
ll a[Maxn];

ll Solve(int ind, ll val)
{
    ll res = 0;
    while (ind < n) {
        int lef = ind + 1, rig = n - 1;
        while (lef <= rig) {
            int mid = lef + rig >> 1;
            if (val < a[mid]) lef = mid + 1;
            else rig = mid - 1;
        }
        res += val * ll(lef - ind);
        ind = lef;
        if (ind < n) val %= a[ind];
    }
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
        if (i) a[i] = min(a[i - 1], a[i]);
    }
    set <ll> S;
    S.insert(a[n - 1] - 1);
    for (int i = n - 2; i >= 0; i--) {
        vector <ll> seq;
        for (auto it = S.begin(); it != S.end() && *it + a[i + 1] < a[i]; it++) {
            ll tk = (a[i] - 1 - *it) / a[i + 1];
            seq.push_back(*it + tk * a[i + 1]);
        }
        seq.push_back(a[i] - 1);
        for (auto el: seq)
            S.insert(el);
    }
    ll res = 0;
    for (auto el: S)
        res = max(res, Solve(0, el));
    printf("%lld\n", res);
    return 0;
}