#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h;
    cin >> w >> h;
    int u1, d1;
    int u2, d2;
    cin >> u1 >> d1;
    cin >> u2 >> d2;
    while (h > 0) {
        w += h;
        if (h == d1)
            w = max(w - u1, 0);
        if (h == d2)
            w = max(w - u2, 0);
        h--;
    }
    cout << w << "\n";
    return 0;
}
