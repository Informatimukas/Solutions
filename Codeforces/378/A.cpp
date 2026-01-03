#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int res1 = 0, draw = 0, res2 = 0;
    for (int i = 1; i <= 6; i++)
        if (abs(a - i) < abs(b - i))
            ++res1;
        else if (abs(a - i) > abs(b - i))
            ++res2;
        else ++draw;
    cout << res1 << " " << draw << " " << res2 << "\n";
    return 0;
}
