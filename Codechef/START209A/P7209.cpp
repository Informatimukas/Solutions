#include <bits/stdc++.h>
using namespace std;

int Solve(int tot, int a, int b) {
    int tk = tot - 1;
    return max(0, min(a, b) - tk);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << max(Solve(a + d, b, c), Solve(b + c, a, d)) << "\n";
    }
    return 0;
}
