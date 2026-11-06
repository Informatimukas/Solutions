#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int odd = 0, ev = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2)
                odd++;
            else ev++;
        }
        if (odd % 2 == 0 || odd % 2 != 0 && odd / 2 + ev != 1)
            cout << "Moggity\n";
        else cout << "Larpity\n";
    }
    return 0;
}
