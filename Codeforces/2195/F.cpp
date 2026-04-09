#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct parabola {
    ll a, b, c;
    int ind;
    bool operator<(const parabola& oth) const {
        if (a != oth.a)
            return a < oth.a;
        return c < oth.c;
    }
};

bool Good(const parabola& p1, const parabola& p2) {
    if (p1.a == p2.a)
        return p1.b == p2.b && p1.c != p2.c;
    return (p1.b - p2.b) * (p1.b - p2.b) - 4 * (p1.a - p2.a) * (p1.c - p2.c) < 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<parabola> p(n);
        vector<int> L(n), R(n);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i].a >> p[i].b >> p[i].c;
            p[i].ind = i;
        }
        sort(p.begin(), p.end());
        for (int i = 0; i < n; i++) {
            L[i] = 1;
            for (int j = 0; j < i; j++)
                if (Good(p[j], p[i]))
                    L[i] = max(L[i], L[j] + 1);
        }
        for (int i = n - 1; i >= 0; i--) {
            R[i] = 1;
            for (int j = i + 1; j < n; j++)
                if (Good(p[i], p[j]))
                    R[i] = max(R[i], R[j] + 1);
            res[p[i].ind] = L[i] + R[i] - 1;
        }
        for (int i = 0; i < n; i++)
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
    }
    return 0;
}
