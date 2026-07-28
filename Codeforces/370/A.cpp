#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int R1, C1, R2, C2;
    cin >> R1 >> C1 >> R2 >> C2;
    int res1 = (R1 != R2) + (C1 != C2);
    int res2 = (R1 + C1) % 2 != (R2 + C2) % 2 ? 0 : (R1 + C1 != R2 + C2) + (R1 - C1 != R2 - C2);
    int res3 = max(abs(R1 - R2), abs(C1 - C2));
    cout << res1 << " " << res2 << " " << res3 << "\n";
    return 0;
}
