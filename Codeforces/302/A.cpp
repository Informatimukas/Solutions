#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a < 0) neg++;
        else pos++;
    }
    while (m--) {
        int l, r;
        cin >> l >> r;
        if ((r - l + 1) % 2 == 0 && (r - l + 1) / 2 <= min(neg, pos))
            cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}
