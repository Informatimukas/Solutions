#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ci = pair<char, ll>;

void Add(vector<int>& BIT, ll x, int val) {
    for (int i = x; i > 0; i -= i & -i)
        BIT[i] += val;
}

int Get(const vector<int>& BIT, ll x) {
    int res = 0;
    for (int i = x; i < BIT.size(); i += i & -i)
        res += BIT[i];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ci> seq(n + 1);
        seq[0] = {'s', 0};
        vector<ll> tmp(n);
        iota(tmp.begin(), tmp.end(), 1);
        set S(tmp.begin(), tmp.end());
        for (int i = 1; i <= n; i++) {
            cin >> seq[i].first >> seq[i].second;
            if (seq[i].first == 'p')
                S.erase(seq[i].second);
        }
        vector<int> BIT(n + 1);
        for (int i = 1; i <= n; i++)
            Add(BIT, i, 1);
        vector<ll> res(n + 1);
        for (int i = n; i >= 1; i--) {
            if (seq[i].first == 'p')
                res[i] = seq[i].second;
            else {
                ll lef = *S.begin();
                ll rig = *S.rbegin();
                while (lef <= rig) {
                    ll mid = (lef + rig) / 2;
                    ll x = *S.lower_bound(mid);
                    res[i] = x;
                    Add(BIT, x, -1);
                    ll got = Get(BIT, x);
                    int j = i - 1;
                    while (seq[j].first == 'p') {
                        Add(BIT, seq[j].second, -1);
                        got += Get(BIT, seq[j].second);
                        j--;
                    }
                    got += seq[j].second;
                    while (j < i - 1) {
                        j++;
                        Add(BIT, seq[j].second, 1);
                    }
                    Add(BIT, x, 1);
                    if (got > seq[i].second)
                        lef = mid + 1;
                    else if (got < seq[i].second)
                        rig = mid - 1;
                    else break;
                }
                S.erase(res[i]);
            }
            Add(BIT, res[i], -1);
        }
        for (int i = 1; i <= n; i++)
            cout << res[i] << (i + 1 <= n ? ' ' : '\n');
    }
    return 0;
}
