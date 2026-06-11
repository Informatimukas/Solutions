#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int res = 0;
    int wth;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        int cand = (a + m - 1) / m;
        if (cand >= res) {
            res = cand;
            wth = i;
        }
    }
    cout << wth << "\n";
    return 0;
}
