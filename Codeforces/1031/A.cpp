#include <bits/stdc++.h>
using namespace std;

int Gilded(int r, int c) {
    if (r == 1)
        return c;
    if (c == 1)
        return r;
    return 2 * r + 2 * c - 4;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, h, k;
    cin >> w >> h >> k;
    int res = 0;
    for (int i = 0; i < k; i++)
        res += Gilded(w - 4 * i, h - 4 * i);
    cout << res << "\n";
    return 0;
}
