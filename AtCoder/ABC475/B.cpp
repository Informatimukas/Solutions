#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    array<int, 3> cnt{};
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        a %= 1000;
        if (a)
            a = 1000 - a;
        cnt[2] += a / 100;
        a %= 100;
        cnt[1] += a / 10;
        a %= 10;
        cnt[0] += a;
    }
    for (int i = 0; i < 3; i++)
        cout << cnt[i] << (i + 1 < 3 ? ' ' : '\n');
    return 0;
}
