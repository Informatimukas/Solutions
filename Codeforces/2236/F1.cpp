#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr ll mod = 1000000007;
constexpr int Maxm = 500005;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> mx(Maxm);
    for (int i = 2; i < Maxm; i++)
        if (mx[i] == 0)
            for (int j = i; j < Maxm; j += i)
                mx[j] = i;
    int T;
    cin >> T;
    while (T--) {
        map<int, int> M;
        int n, x;
        cin >> n >> x;
        while (n--) {
            int a;
            cin >> a;
            while (a > 1) {
                M[mx[a]]++;
                a /= mx[a];
            }
        }
        ll res = 1;
        for (auto x : M | views::values)
            res = res * (x + 1) % mod;
        cout << res << "\n";
    }
    return 0;
}
