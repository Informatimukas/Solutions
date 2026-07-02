#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    bool was1 = false;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 1)
            was1 = true;
    }
    cout << (was1 ? -1 : 1) << "\n";
    return 0;
}
