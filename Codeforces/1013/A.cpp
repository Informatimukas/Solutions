#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int asum = 0, bsum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        asum += a;
    }
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        bsum += b;
    }
    cout << (asum >= bsum ? "Yes" : "No") << "\n";
    return 0;
}
