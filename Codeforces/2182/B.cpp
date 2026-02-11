#include <bits/stdc++.h>
using namespace std;

int Solve(int a, int b) {
    int res = 0;
    while (a > 0) {
        ++res;
        --a;
        a /= 2;
        b /= 2;
        swap(a, b);
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
        int a, b;
        cin >> a >> b;
        cout << max(Solve(a, b), Solve(b, a)) << "\n";
    }
    return 0;
}
