#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int res = 0;
    int n, m;
    cin >> n >> m;
    for (int a = 0; a <= 1000; a++)
        for (int b = 0; b <= 1000; b++)
            if (a * a + b == n && a + b * b == m)
                ++res;
    cout << res << "\n";
    return 0;
}