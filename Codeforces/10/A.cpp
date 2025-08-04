#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
    vector<ii> seq(n);
    for (auto& [a, b] : seq)
        cin >> a >> b;
    int res = 0;
    int lst = seq[0].first;
    for (auto& [a, b] : seq) {
        int tim = a - lst;
        int tk = min(t1, tim);
        res += tk * p1;
        tim -= tk;
        tk = min(t2, tim);
        res += tk * p2;
        tim -= tk;
        res += tim * p3;
        res += (b - a) * p1;
        lst = b;
    }
    cout << res << "\n";
    return 0;
}
