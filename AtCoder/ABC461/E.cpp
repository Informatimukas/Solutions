#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;
using ll = long long;

void Add(vector<ii>& BIT, int key, const ii& val) {
    for (int i = key; i < BIT.size(); i += i & -i) {
        BIT[i].first += val.first;
        BIT[i].second += val.second;
    }
}

ii Get(const vector<ii>& BIT, int key) {
    ii res;
    for (int i = key; i > 0; i -= i & -i) {
        res.first += BIT[i].first;
        res.second += BIT[i].second;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector myr(n + 1, 1);
    vector myc(n + 1, 2);
    vector<ii> BIT(q + 3, {0, 0});
    Add(BIT, 1, {n, 0});
    Add(BIT, 2, {0, n});
    ll blacks = 0;
    for (int i = 3; i <= 2 + q; i++) {
        int typ;
        cin >> typ;
        if (typ == 1) {
            int r;
            cin >> r;
            int ind = myr[r];
            myr[r] = i;
            Add(BIT, ind, {-1, 0});
            Add(BIT, i, {1, 0});
            blacks += (Get(BIT, i).second - Get(BIT, ind).second);
        } else {
            int c;
            cin >> c;
            int ind = myc[c];
            myc[c] = i;
            Add(BIT, ind, {0, -1});
            Add(BIT, i, {0, 1});
            blacks -= (Get(BIT, i).first - Get(BIT, ind).first);
        }
        cout << blacks << "\n";
    }
    return 0;
}
