#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int l = n;
    int m = (n + 2) / 2;
    cout << m << "\n";
    for (int i = 1; i <= m && l > 0; i++) {
        cout << "1 " << i << "\n";
        l--;
    }
    for (int i = 2; i <= m && l > 0; i++) {
        cout << i << " " << m << "\n";
        l--;
    }
    return 0;
}
