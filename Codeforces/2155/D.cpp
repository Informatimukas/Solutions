#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

bool Ask(int a, int b, set<ii>& S) {
    if (a > b)
        swap(a, b);
    if (S.contains({a, b}))
        return false;
    S.emplace(a, b);
    cout << a + 1 << " " << b + 1 << endl;
    int res;
    cin >> res;
    return res;
}

void Solve(int n) {
    set<ii> S;
    for (int d = 1; d < n; d++)
        for (int i = 0; i < n; i++) {
            int j = (i + d) % n;
            if (Ask(i, j, S))
                return;
        }
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
        Solve(n);
    }
    return 0;
}
