#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

constexpr int Inf = 1000000000;

int Next(int x) {
    return x % 2 ? x + 1 : x / 2;
}

int Count(int x, int target) {
    int res = 0;
    while (x != target) {
        res++;
        x = Next(x);
    }
    return res;
}

int Solve(const vector<int>& a, int target) {
    vector<ii> seq(a.size());
    ii mn = {Inf, 0};
    for (int i = 0; i < a.size(); i++) {
        seq[i] = {Count(a[i], target), a[i]};
        mn = min(mn, seq[i]);
    }
    int res = 0;
    bool cont = true;
    while (cont) {
        cont = false;
        for (auto& p : seq)
            if (p != mn) {
                cont = true;
                while (p != mn) {
                    res++;
                    p.first--;
                    p.second = Next(p.second);
                    mn = min(mn, p);
                }
            }
    }
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
        vector<int> a(n);
        for (auto& x : a)
            cin >> x;
        cout << min(Solve(a, 1), Solve(a, 2)) << "\n";
    }
    return 0;
}
