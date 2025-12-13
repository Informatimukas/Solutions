#include <bits/stdc++.h>
using namespace std;

using ii = pair<int, int>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int res = 0;
    set<ii> S;
    while (m--) {
        int r, c;
        cin >> r >> c;
        bool ok = true;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (S.contains({r + i, c + j}))
                    ok = false;
        if (ok) {
            res++;
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    S.emplace(r + i, c + j);
        }
    }
    cout << res << "\n";
    return 0;
}
