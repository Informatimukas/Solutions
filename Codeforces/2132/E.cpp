#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

void readAndSum(vector<int>& a, vector<ll>& suma) {
    for (int i = 1; i < a.size(); i++)
        cin >> a[i];
    sort(a.begin() + 1, a.end(), greater<>());
    for (int i = 1; i < suma.size(); i++)
        suma[i] = suma[i - 1] + a[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(n + 1), b(m + 1);
        vector<ll> suma(n + 1), sumb(m + 1);
        vector<ii> best(n + m + 1);
        readAndSum(a, suma);
        readAndSum(b, sumb);
        ii cur = {0, 0};
        int i = 1, j = 1;
        for (int z = 1; z <= n + m; z++) {
            if (i <= n && (j > m || a[i] >= b[j])) {
                cur.first++;
                i++;
            } else {
                cur.second++;
                j++;
            }
            best[z] = cur;
        }
        while (q--) {
            int x, y, z;
            cin >> x >> y >> z;
            ii cur = best[z];
            if (cur.first > x) {
                int tk = cur.first - x;
                cur.first -= tk;
                cur.second += tk;
            }
            if (cur.second > y) {
                int tk = cur.second - y;
                cur.first += tk;
                cur.second -= tk;
            }
            cout << suma[cur.first] + sumb[cur.second] << "\n";
        }
    }
    return 0;
}
