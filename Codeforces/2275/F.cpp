#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int Maxn = 1000005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> mx(Maxn);
    for (int i = 2; i < Maxn; i++)
        if (mx[i] == 0)
            for (int j = i; j < Maxn; j += i)
                mx[j] = i;
    int T;
    cin >> T;
    while (T--) {
        map<int, int> M;
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
            int y = 1;
            while (x > 1) {
                int cur = mx[x];
                int cnt = 0;
                while (mx[x] == cur) {
                    x /= cur;
                    cnt++;
                }
                if (cnt % 2)
                    y *= cur;
            }
            ++M[y];
            x = y;
        }
        ll res = 0;
        set<int> S;
        for (auto x : a) {
            while (x > 1) {
                int cur = mx[x];
                int cnt = 0;
                while (mx[x] == cur) {
                    x /= cur;
                    ++cnt;
                }
                if (cnt % 2) {
                    if (S.contains(cur))
                        S.erase(cur);
                    else S.insert(cur);
                }
            }
            int my = 1;
            for (auto z : S)
                if (my <= Maxn / z)
                    my *= z;
                else {
                    my = Maxn;
                    break;
                }
            auto it = M.find(my);
            if (it != M.end())
                res += it->second;
        }
        cout << res << "\n";
    }
    return 0;
}
