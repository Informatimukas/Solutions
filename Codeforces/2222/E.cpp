#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int Insert(ll x) {
    cout << "I " << x << endl;
    int res;
    cin >> res;
    return res;
}

int Query(ll y) {
    cout << "Q " << y << endl;
    int res;
    cin >> res;
    return res;
}

void Answer(int k, ll c) {
    cout << "A " << k << " " << c << endl;
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
        ll all = (1ll << n) - 1ll;
        cout << all << endl;
        int siz = Insert(0);
        if (siz == 1) {
            if (Insert(all) == 1)
                Answer(2, all);
            else Answer(3, all);
            continue;
        }
        if (Query(1) == 1) {
            ll c = 0;
            for (int i = 0; i < n; i++)
                if (Insert(1ll << i) > siz) {
                    c |= 1ll << i;
                    siz++;
                }
            Answer(1, c);
            continue;
        }
        if (Insert(all) > siz) {
            siz++;
            ll c = 0;
            for (int i = n - 2; i >= 0; i--)
                if (Query(c | 1ll << i) >= siz)
                    c |= 1ll << i;
            if (Insert(c) <= siz)
                c ^= all;
            Answer(3, c);
            continue;
        }
        ll c = 0;
        for (int i = n - 1; i >= 0; i--)
            if (Query(c | 1ll << i) >= siz)
                c |= 1ll << i;
        Answer(2, c);
    }
    return 0;
}
